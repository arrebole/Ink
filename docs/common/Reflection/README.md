## 运行时类型判断

#### go reflect

+ TypeOf()
+ ValueOf()

##### 反射三定律

1、反射可以将“接口类型变量”转换为“反射类型对象” 

2、反射可以将“反射类型对象”转换为“接口类型变量” 

3、如果要修改反射类型对象，其值必须是“addressable” 



#### c++ typeid

+ name()

```cpp
//     
if (typeid(*animal) == typeid(Dog))
    {
    	cout<< typeid(*animal).name()<<endl;
        // dynamic_cast 类型转换父转子
        Dog *a = dynamic_cast<Dog *>(animal);
        a->eat();
    }
```

