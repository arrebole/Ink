

function combine(n , k) {
	const bt = new Backtrack()
	bt.backtrack(1, k, n)
	return bt.out
}

class Backtrack{
	constructor(){
		this.out = []
		this.curr = []
	}

	backtrack(i, k, n) {
		if (this.curr.length == k) {
			this.out.push(this.curr.slice())
			return
		}
		for ( let j = i; j <= n; j++) {
			this.curr.push(j)
			this.backtrack(j+1, k, n)
			this.curr.pop()
		}
	}
}


console.log(combine(4, 2))