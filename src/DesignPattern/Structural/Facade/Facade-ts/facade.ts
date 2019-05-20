export interface IFacade {
    Cooking(): string
}

export class Facade implements IFacade {
    constructor() {
        this.chef = new Chef();
    }
    private chef: Chef; //子系统
    public Cooking(): string {
        return this.chef.CookingDish() + this.chef.CookingRice();
    }
}

class Chef {
    public CookingRice(): string {
        return "rice\n";
    }

    public CookingDish(): string {
        return "dish\n"
    }
}