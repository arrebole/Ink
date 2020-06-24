#! /usr/bin/env deno

// 行星抽象接口
interface IPlanet {
    rotation(): void
}

// 行星抽象接口
interface PlanetCreator{
    create():IPlanet
}

// 具体的产品：地球
class Earth implements IPlanet {
    public rotation() {
        // ...     
    }
};

// 具体的产品：火星
class Mars implements IPlanet {
    public rotation() {
        // ...     
    }
};


class EarthCreator implements PlanetCreator{
    create():IPlanet{
        return new Earth();
    }
}

class MarsCreator implements PlanetCreator{
    create():IPlanet{
        return new Mars();
    }
}

function sample(factory: PlanetCreator) {
    const planet = factory.create();
    planet.rotation()
}
