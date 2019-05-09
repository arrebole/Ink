import { IGun,IGunCreator } from "./gun/gun"
import { RifleGunCreator,SubmachineGunCreator } from "./gun/concreteGun"

function TestCreator(f:IGunCreator){
    f.createGun().biubiubiu()
}

let t1:IGunCreator = new RifleGunCreator();
let t2:IGunCreator = new SubmachineGunCreator();
TestCreator(t1)
TestCreator(t2)