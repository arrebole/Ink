interface IFacade {
    TurnOff(): void;
    PlayMusic(): void;
};

class Light {
    TurnOffLight() {
        console.log("turn off the light");
    }
};

class Mp3 {
    PlayMusic() {
        console.log("mp3 play music");
    }
};

class Facade implements IFacade {
    private light: Light;
    private mp3: Mp3;

    constructor() {
        this.light = new Light();
        this.mp3 = new Mp3();
    }
    TurnOff() {
        this.light.TurnOffLight();
    }
    PlayMusic() {
        this.mp3.PlayMusic();
    }

};

function main() {
    const f = new Facade();
    f.TurnOff();
    f.PlayMusic();
    return 0;
}