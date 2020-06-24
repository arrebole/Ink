interface Button{ }
interface Menu{ }

interface Factory{
    createButton(): Button;
    createMenu(): Menu;
}

class LinuxButton implements Button{}
class LinuxMenu implements Menu{}
class LinuxFactory implements Factory{
    createButton():Button{
        return new LinuxButton();
    }
    createMenu():Menu{
        return new LinuxMenu();
    }
}


class WinButton implements Button{}
class WinMenu implements Menu{}
class WinFactory implements Factory{
    createButton():Button{
        return new WinButton();
    }
    createMenu():Menu{
        return new WinMenu();
    }
}

function sample(factory: Factory){
    const button = factory.createButton()
    const menu = factory.createMenu()
}