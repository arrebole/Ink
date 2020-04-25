# gRPC

**gRPC**是Google发起的一个开源远程过程调用系统。该系统基于HTTP/2协议传输，使用`Protocol Buffers`作为接口描述语言。

## Table of Contents

+ [安装依赖]()
  + `protobuf`
  + `protoc plugin`
+ [Helloworld]()



## 安装依赖

### protobuf

`Protocol Buffers`是跨语言的序列化框架，其作用是将不同编程语言的对象结构，转化为统一的二进制格式。这种方式可以类比于json，在不同语言下能够互相转换成不同语言的对象，但是json是按照字符串的方式存储的，比起二进制格式它的存储和系列化会消耗更多的空间用和cpu资源。

**程序安装地址**(解释性语言不需要要)

```bash
https://github.com/protocolbuffers/protobuf/releases
```

### protoc plugin

`protoc plugin` 是`protobuf`的插件，**强类型语言需要结构类型定义，用它可以把proto文件快速生成类型定义**。由于在使用`protobuf`时会指定插件，此时程序会在`path`环境变量的目录下去查找这个插件。所以确保安装的插件被添加到`path`环境变量下。

**程序安装地址**(解释性语言不需要要)

```bash
github.com/golang/protobuf/protoc-gen-go # go
```



## HelloWorld

我们使用`golang`演示`gRPC`的`helloworld`版本

#### 1.编写proto文件 

**helloworld/helloworld.proto**

```protobuf
syntax = "proto3";

option go_package = ".;helloworld";

package helloworld;

// The greeting service definition.
service Greeter {
  // Sends a greeting
  rpc SayHello (HelloRequest) returns (HelloReply) {}
}

// The request message containing the user's name.
message HelloRequest {
  string name = 1;
}

// The response message containing the greetings
message HelloReply {
  string message = 1;
}
```

#### 2.编译proto文件

**helloworld.proto -> helloworld.bp.go**

```bash
# /helloworld/helloworld
#				--helloworld.proto
protoc ./helloworld.proto --go_out=plugins=grpc:./
```

#### 3.编写服务端

```go
package main

import (
	"context"
	"log"
	"net"
	"google.golang.org/grpc"
	pb "grpc/helloworld/helloworld"
)

const port = ":50051"

// server is used to implement helloworld.GreeterServer.
type server struct {
	pb.UnimplementedGreeterServer
}

// SayHello implements helloworld.GreeterServer
func (s *server) SayHello(ctx context.Context, in *pb.HelloRequest) (*pb.HelloReply, error) {
	log.Printf("Received: %v", in.GetName())
	return &pb.HelloReply{ Message: "Hello " + in.GetName() }, nil
}

func main() {
	lis, err := net.Listen("tcp", port)
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}
	s := grpc.NewServer()
	pb.RegisterGreeterServer(s, &server{})
	if err := s.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}
}
```

#### 4.编译服务端

```bash
go build -o server.exe ./greeter_server/main.go
```

#### 5.编写客户端

```go
package main

import (
	"context"
	"log"
	"os"
	"time"

	"google.golang.org/grpc"

	pb "grpc/helloworld/helloworld"
)

const (
	address     = "localhost:50051"
	defaultName = "world"
)

func main() {
	// Set up a connection to the server.
	conn, err := grpc.Dial(address, grpc.WithInsecure(), grpc.WithBlock())
	if err != nil {
		log.Fatalf("did not connect: %v", err)
	}
	defer conn.Close()
	c := pb.NewGreeterClient(conn)

	// Contact the server and print out its response.
	name := defaultName
	if len(os.Args) > 1 {
		name = os.Args[1]
	}
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()
	r, err := c.SayHello(ctx, &pb.HelloRequest{Name: name})
	if err != nil {
		log.Fatalf("could not greet: %v", err)
	}
	log.Printf("Greeting: %s", r.GetMessage())
}
```

#### 6.编译客户端

```bash
go build -o client.exe ./greeter_client/main.go
```

#### 7.运行

```bash
.\server.exe
.\client.exe
# 2020/04/25 20:17:22 Greeting: Hello world
```

