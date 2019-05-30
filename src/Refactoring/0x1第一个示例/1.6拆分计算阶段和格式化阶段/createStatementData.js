let Plays = null;

function createStatementData(invoice, plays) {
    const statementData = {};
    Plays = plays;
    statementData.customer = invoice.customer;
    statementData.performances = invoice.performances.map(enrichPerformance);
    statementData.totalAmount = totalAmount(statementData);
    statementData.totalVolumeCredits = totalVolumeCredits(statementData);
    return statementData;
}

function playFor(aPerformance) {
    return Plays[aPerformance.playID]

}

function enrichPerformance(aPerformance) {
    const result = Object.assign({}, aPerformance);
    result.play = playFor(result);
    result.amount = amountFor(result);
    result.volumeCredits = volumeCreditsFor(result);
    return result;
}

function totalAmount(data) {
    return data.performances
        .reduce((total, p) => total + p.amount, 0)
}

function totalVolumeCredits(data) {
    return data.performances
        .reduce((total, p) => total + p.volumeCredits, 0);
}


function volumeCreditsFor(aPerformance) {
    let result = 0;
    result += Math.max(aPerformance.audience - 30, 0);
    if ("comedy" == aPerformance.play.type) result += Math.floor(aPerformance.audience / 5);
    return result;
}

function amountFor(aPerformance) {
    let result = 0;

    switch (aPerformance.play.type) {
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
            throw new Error(`Unknown type: ${aPerformance.play.type}`)
    }
    return result;
}

module.exports = createStatementData;