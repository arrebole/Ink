const fs = require("fs")


function statement(invoice, plays) {
    const statementData = {};
    statementData.customer = invoice.customer;
    statementData.performances = invoice.performances.map(enrichPerformance);
    return renderPlainText(statementData, invoice, plays);
}

function enrichPerformance(aPerformance){
    const result = Object.assign({},aPerformance);
    result.play = playFor(result);
    return result;
}


function renderPlainText(data , plays) {
    let result = `Statement for ${data.customer} \n`;

    for (let perf of data.performances) {
        // print line for this order
        result += `${playFor(perf).name}: ${amountFor(perf) / 100} (${perf.audience} seats) \n`;
    }

    result += `Amount owed is ${usd(totalAmount(data) / 100)} \n`;
    result += `You earned ${totalVolumeCredits(data)} credits \n`;
    return result;
}


function totalAmount(data) {
    let result = 0;
    for (let perf of data.performances) {
        result += amountFor(perf)
    }
    return result;
}

function totalVolumeCredits(data) {
    let result = 0;
    for (let perf of data.performances) {
        result += volumeCreditsFor(perf);
    }
    return result;
}


function usd(aNumber) {
    return new Intl.NumberFormat("en-US",
        {
            style: "currency",
            currency: "USD",
            minimumFractionDigits: 2
        }
    ).format(aNumber);
}

function playFor(aPerformance) {
    return plays[aPerformance.playID]
}

function volumeCreditsFor(perf) {
    let result = 0;
    result += Math.max(perf.audience - 30, 0);
    if ("comedy" == playFor(perf).type) result += Math.floor(perf.audience / 5);
    return result;
}

function amountFor(aPerformance) {
    let result = 0;

    switch (playFor(aPerformance).type) {
        case "tragedy":
            result = 40000;
            if (aPerformance.audience > 30) {
                result += 10000 * (aPerformance.audience - 30);
            }
            break;
        case "comedy":
            result = 30000;
            if (aPerformance.audience > 20) {
                result += 10000 + 500 * (aPerformance.audience - 20);
            }
            result += 300 * aPerformance.audience;
            break;
        default:
            throw new Error(`Unknown type: ${playFor(perf).type}`)
    }
    return result;
}



/**
 * 
 * @param {String} fileName
 * @returns {Object} object
 */
function readJsonToObject(fileName) {
    let file = fs.readFileSync(fileName);
    return JSON.parse(file.toString())
}


let invoices = readJsonToObject('./invoices.json');
let plays = readJsonToObject('./plays.json');

for (let invoice of invoices) {
    let data = statement(invoice, plays);
    console.log(data);
}
