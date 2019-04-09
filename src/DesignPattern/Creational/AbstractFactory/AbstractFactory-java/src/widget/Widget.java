package widget;

interface Button {
    void drawButton();
}

interface Menu {
    void drawMenu();
}

// -------------------------------------------

class LinuxButton implements Button {
    public void drawButton() {
        System.out.println("draw LinuxButton");
    }
}

class WindowsButton implements Button {
    public void drawButton() {
        System.out.println("draw WindowsButton");
    }
}

class LinuxMenu implements Menu {
    public void drawMenu() {
        System.out.println("draw LinuxMenu");
    }
}

class WindowsMenu implements Menu {
    public void drawMenu() {
        System.out.println("draw WindowsMenu");
    }
}

// -------------------------------------

interface Factory {
    Button createButton();

    Menu createMenu();
}

class LinuxFactory implements Factory {
    public Button createButton() {
        return new LinuxButton();
    }

    public Menu createMenu() {
        return new LinuxMenu();
    }
}

class WindowsFactory implements Factory {
    public Button createButton() {
        return new WindowsButton();
    }

    public Menu createMenu() {
        return new WindowsMenu();
    }
}

// ------------------------------------

public class Widget {

    public static enum type {
        linux, windows,
    }

    private Button button;
    private Menu menu;

    public Widget(type t) {
        Factory factory = null;
        switch (t) {
        case linux:
            factory = new LinuxFactory();
            break;
        case windows:
            factory = new WindowsFactory();
            break;
        }
        this.button = factory.createButton();
        this.menu = factory.createMenu();
    }

    public void draw() {
        button.drawButton();
        menu.drawMenu();
    }
}