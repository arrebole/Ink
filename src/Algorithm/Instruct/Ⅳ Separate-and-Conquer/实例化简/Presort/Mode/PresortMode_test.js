const { PresortMode } = require("./PresortMode")

function TestPresortMode(){
    let data = [1,3,7,7,727,27,7,2,5,62,77,8,8,3,57,7,2,674,1,2]
    if(PresortMode(data)!= 7){
        console.error("test Fail")
        return;
    }
    console.log("test PASS!~")
}

TestPresortMode()