import { HumanTypes, HumanFactory, StandardHumanFactory } from "./Human";

//----------client-------------
// 设计模式：创建型—抽象工厂
// 算法：——
// 复杂度：——
// 描述：仅使用由 AbstractFactory 和 AbstractProduct类声明的接口
function Client(f: HumanFactory,t:HumanTypes) {
    f.createClothes(t).beWearing();
    f.createPeople(t).yingyingying();
}

function main() {
    Client(StandardHumanFactory.Instance(),HumanTypes.Man);
    Client(StandardHumanFactory.Instance(),HumanTypes.Woman);
}

main()