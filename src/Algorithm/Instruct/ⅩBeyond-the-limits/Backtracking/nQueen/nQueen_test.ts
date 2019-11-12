import { NQueen } from "./nQueen";



function TestNQueen(){
    const result = new NQueen(4).exec()
    console.log(result)
}

TestNQueen()