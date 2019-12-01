// 重构：以多态取代条件表达式

namespace BadSmell {
    function plumages(birfs: any[]) {
        return new Map(birfs.map(b => [b.name, plumage(b)]))
    }
    function speeds(birfs: any[]) {
        return new Map(birfs.map(b => [b.name, airSpeedVelocity(b)]))
    }
    function plumage(birfs: { type: string, numberOfCocnuts: number, voltage: number }) {
        switch (birfs.type) {
            case "EuropeanSwallow":
                return "average";
            case "AfricanSwallow":
                return (birfs.numberOfCocnuts > 2) ? "tired" : "average";
            case "NorwegianBlueParrot":
                return (birfs.voltage > 100) ? "scorched" : "beautiful";
            default:
                return "unknown";
        }
    }
    function airSpeedVelocity(birfs: { type: string, numberOfCocnuts: number, voltage: number, isNailed: boolean }) {
        switch (birfs.type) {
            case "EuropeanSwallow":
                return 35;
            case "AfricanSwallow":
                return 40 - 2 * birfs.numberOfCocnuts;
            case "NorwegianBlueParrot":
                return (birfs.isNailed) ? 0 : 10 + birfs.voltage / 10;
            default:
                return null;
        }
    }
}
namespace GoodSmell {
    type birdData = {
        type: string,
        numberOfCocnuts: number,
        voltage: number,
        isNailed: boolean,
        name:string
    }
    abstract class Bird {
        constructor(birdObj: birdData) {
            this.name = birdObj.name
            this.type = birdObj.type
            this.numberOfCocnuts = birdObj.numberOfCocnuts
            this.voltage = birdObj.voltage
        }
        name: string;
        type: string;
        numberOfCocnuts: number;
        voltage: number;
        isNailed: boolean;
        abstract get plumage(): string;
        abstract get airSpeedVelocity(): number;
    }
    class EuropeanSwallow extends Bird {
        get plumage(): string {
            return "average";
        }
        get airSpeedVelocity(): number {
            return 35;
        }
    }
    class AfricanSwallow extends Bird {
        get plumage(): string {
            return (this.numberOfCocnuts > 2) ? "tired" : "average";
        }
        get airSpeedVelocity(): number {
            return 40 - 2 * this.numberOfCocnuts;
        }
    }
    class NorwegianBlueParrot extends Bird {
        get plumage(): string {
            return (this.voltage > 100) ? "scorched" : "beautiful";
        }
        get airSpeedVelocity(): number {
            return (this.isNailed) ? 0 : 10 + this.voltage / 10;
        }
    }

    function createBird(bird: birdData): Bird {
        switch (bird.type) {
            case "EuropeanSwallow":
                return new EuropeanSwallow(bird);
            case "AfricanSwallow":
                return new AfricanSwallow(bird);
            case "NorwegianBlueParrot":
                return new NorwegianBlueParrot(bird);
            default:
                throw new Error("error");
        }
    }
    
    function plumages(birds: birdData[]) {
        return new Map(birds
            .map(b => createBird(b))
            .map(bird => [bird.name, bird.plumage]))
    }
    function speeds(birds: birdData[]) {
        return new Map(birds
            .map(b => createBird(b))
            .map(bird => [bird.name, bird.airSpeedVelocity])
        )
    }

}