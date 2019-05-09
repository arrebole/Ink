import { Director, Room, TerrorRoomBuilder } from "./room/room"

let waiter: Director = new Director();
let room: Room = waiter.makeRoombyBuilder(new TerrorRoomBuilder());

room.openDoor();
room.openWindow();
