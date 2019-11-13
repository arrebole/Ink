const { PresortElementUniqueness } = require("./ElementUniqueness");

function TestPresortElementUniqueness(){
    let data = [1,4,6,7,8,9,2,5,7,9,0];
    
    if(PresortElementUniqueness(data)){
        console.error("test Fail");
        return;
    }

    data = [1,0,3,8,4,10,2,5,7,12,24,11,16,40,25]
    if (!PresortElementUniqueness(data)){
        console.error("test Fail");
        return
    }

    console.log("test PASS")
}

TestPresortElementUniqueness()