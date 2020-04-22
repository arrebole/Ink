const { presortSearch } = require("./PresortSearch");


function TestPresortSearch(){
    let data = [1,9,7,3,6,8,0,3,78,4,41,5,52,2,62]
    presortSearch(data,4);
}

TestPresortSearch()