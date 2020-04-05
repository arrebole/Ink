interface Command {
    execute()
}

class Stock {
    private name = "ABC";
    private quantity = 10;

    buy() {
        console.log("Stock [ Name: " + this.name + ", Quantity: " + this.quantity + " ] bought");
    }
    sell() {
        console.log("Stock [ Name: " + this.name + ", Quantity: " + this.quantity + " ] sold");
    }
}

class BuyStock implements Command {
    private abcStock: Stock;

    constructor(abcStock: Stock) {
        this.abcStock = abcStock
    }

    execute() {
        this.abcStock.buy();
    }
}

class SellStock implements Command {
    private abcStock: Stock;

    constructor(abcStock: Stock) {
        this.abcStock = abcStock
    }

    execute() {
        this.abcStock.sell();
    }
}

function main() {
    const abcStock = new Stock();

    const buyStockOrder = new BuyStock(abcStock);
    const sellStockOrder = new SellStock(abcStock);
    
    buyStockOrder.execute();
    sellStockOrder.execute()
}