package main

import (
	"net/http"
)

// func index(w http.ResponseWriter, r *http.Request) {

// }

func main() {
	mux := http.NewServeMux()
	fileservice := http.FileServer(http.Dir("./"))
	mux.Handle("/", fileservice)
	service := &http.Server{
		Addr:    ":8080",
		Handler: mux,
	}
	service.ListenAndServe()
}
