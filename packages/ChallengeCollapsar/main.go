package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"net/http"
	"time"
)

var (
	inputThread  int
	inputDesHost string
	inputDesPort string
)

func init() {
	flag.IntVar(&inputThread, "w", 1, "Thread number")
	flag.StringVar(&inputDesHost, "host", "127.0.0.1", "dist host")
	flag.StringVar(&inputDesPort, "port", "443", "Dist port")
	flag.Parse()
}

func NewRequest(url string) *http.Request {
	req, err := http.NewRequest("GET", url, nil)
	if err != nil {
		panic("[http.NewRequest]" + err.Error())
	}
	req.Header.Add("User-Agent", `Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/77.0.3865.75 Safari/537.36`)
	req.Header.Add("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3")
	req.Header.Add("Connection", "keep-alive")
	req.Header.Add("Cache-Control", "max-age=0")
	return req
}

func NewClient() *http.Client {
	tr := &http.Transport{
		MaxIdleConns:       10,
		IdleConnTimeout:    30 * time.Second,
		DisableCompression: true,
	}
	return &http.Client{Transport: tr}
}

func send(client *http.Client, request *http.Request) {
	resp, err := client.Do(request)
	if err != nil {
		fmt.Println("[Error] " + err.Error())
	}
	defer resp.Body.Close()

	// data, _ := ioutil.ReadAll(resp.Body)
	ioutil.ReadAll(resp.Body)
	fmt.Println("[success] ", time.Now().Format("2006-01-02 15:04:05"))
}

func main() {

	for i := 0; i < inputThread; i++ {
		go func() {
			client := NewClient()
			request := NewRequest(fmt.Sprintf("https://%s:%s", inputDesHost, inputDesPort))
			for {
				send(client, request)
			}
		}()
	}

	ch := make(chan int)
	<-ch
}
