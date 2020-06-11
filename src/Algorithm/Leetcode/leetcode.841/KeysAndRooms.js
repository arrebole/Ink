


class KeysAndRooms {
    constructor(rooms) {
        this.Rooms = rooms
        this.Seen = new Array(rooms.length);
        this.Seen.fill(false,0,rooms.length)
    }

    Room = null
    Seen = null
    Stack = new Array();

    resolve(){
        this.mark(0)
        this.dsf()
        return this.isEnterEvery()
    }
    mark(index) {
        this.Stack.push(this.Rooms[index])
        this.Seen[index] = true;
    }

    dsf() {
        while (this.Stack.length > 0) {

            let list = this.Stack.pop()

            if (list.length == 0) {
                continue;
            }

            for (const iterator of list) {
                if (!this.Seen[iterator]) {
                    this.mark(iterator)
                }
            }
        }

    }

    isEnterEvery() {
        for (const i of this.Seen) {
            if(!i) return false;
        }
        return true;
    }
}


/**
 * 
 * @param {number[][]} rooms 
 */
function canVisitAllRooms(rooms) {
    let q = new KeysAndRooms(rooms);
    return q.resolve();
};



console.log(canVisitAllRooms([[1,3],[1,4],[2,3,2,4,1],[],[4,3,2]]))