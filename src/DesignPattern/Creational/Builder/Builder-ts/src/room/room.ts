export class Room {
    public door: string;
    public window: string;
    public openDoor() {
        console.log(this.door)
    }
    public openWindow() {
        console.log(this.window);
    }
}


interface Builder {
    createRoom();
    getRoom(): Room;
    buildDoor();
    buildWindow();
}

export class TerrorRoomBuilder implements Builder {
    private _room: Room = null;
    public createRoom() {
        this._room = new Room();
    }
    public getRoom(): Room {
        return this._room;
    }
    public buildDoor() {
        this._room.door = "terror door";
    }
    public buildWindow() {
        this._room.window = "terror window";
    }
}

export class Director {
    public makeRoombyBuilder(builder: Builder): Room {
        builder.createRoom();
        builder.buildDoor();
        builder.buildWindow();
        return builder.getRoom();
    }
}