
// 产品接口
pub trait Product{
    fn call(&self);
}

// 具体产品a
pub struct ProductA{} 
impl Product for ProductA {
    fn call(&self){
        println!("call PrpductA");
    }
}

// 具体产品b
pub struct ProductB{}
impl Product for ProductB{
    fn call(&self){
        println!("call PrpductB");
    }
}


pub enum ProductId{
    A,
    B,
}

// 设计模式：简单工厂模式
// 算法：——
// 复杂度：——
pub fn simple_factory(name: ProductId)->Box<dyn Product>{
    
    match name {
        ProductId::A => Box::new(ProductA{}),
        ProductId::B => Box::new(ProductB{}),
    }
}

fn main(){
    simple_factory(ProductId::A).call();
    simple_factory(ProductId::B).call();
}