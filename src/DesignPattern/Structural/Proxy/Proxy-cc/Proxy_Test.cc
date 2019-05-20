#include "./Proxy.h"

int main(){
    Subject* handle = new Proxy();
    handle->TouchFile();
}