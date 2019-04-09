
interface IColor {
    getColor(): void;
}

class red implements IColor {
    public getColor(): void {
        console.log("red");
    }
}

class black implements IColor {
    public getColor(): void {
        console.log("black");
    }
}

enum ColorTypes {
    red, black,
}

class ColorFactory {

    public static createColor(t: ColorTypes): IColor {
        switch (t) {
            case ColorTypes.red:
                return new red();
            case ColorTypes.black:
                return new black();
        }
        return null;
    }
}

export {
    ColorFactory,
    ColorTypes,
    IColor,
}
