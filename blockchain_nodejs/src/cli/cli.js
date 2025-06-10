const readline = require('readline');
const { Blockchain } = require('../blockchain');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

const chain = new Blockchain();

function showMenu() {
    console.log("\n1. Add Block");
    console.log("2. Print Chain");
    console.log("3. Validate Chain");
    console.log("4. Exit");

    rl.question("Choose an option: ", answer => {
        switch (answer.trim()) {
            case '1':
                rl.question("Enter transaction data: ", data => {
                    chain.addBlock(data);
                    console.log("Block added.");
                    showMenu();
                });
                break;
            case '2':
                chain.printChain();
                showMenu();
                break;
            case '3':
                console.log(chain.isChainValid() ? "Blockchain is valid." : "Blockchain is INVALID.");
                showMenu();
                break;
            case '4':
                rl.close();
                break;
            default:
                console.log("Invalid option");
                showMenu();
        }
    });
}

function startCLI() {
    console.log("Welcome to Node.js Blockchain CLI");
    showMenu();
}

module.exports = startCLI;
