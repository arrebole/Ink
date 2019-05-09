import { IGun, IGunCreator } from "./gun";

class RifleGun implements IGun {
    public biubiubiu() {
        console.log("RifleGun biubiubiu")
    }
}
export class RifleGunCreator implements IGunCreator {
    public createGun(): IGun {
        return new RifleGun();
    }
}


class SubmachineGun implements IGun {
    public biubiubiu() {
        console.log("SubmachineGun biubiubiu")
    }
}
export class SubmachineGunCreator implements IGunCreator {
    public createGun(): IGun {
        return new SubmachineGun();
    }
}