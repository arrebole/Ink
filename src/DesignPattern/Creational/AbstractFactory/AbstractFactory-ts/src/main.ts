import { Client,DinnerTypes} from "./Dinner";


let my = new Client(DinnerTypes.PlanA);
my.eat();

let my2 = new Client(DinnerTypes.PlanB);
my2.eat();