# Chain Rxn - My Blockchain

Welcome to my implementation of **Project 1** from the **Chain Rxn - BIB Summer Bootcamp**. The goal of this project is to understand and build a simple blockchain from scratch, including:

* Block creation
* Hashing logic
* Blockchain integrity validation
* Proof of Work (Mining mechanism)

---

## Project Overview

Initially, I implemented the blockchain in **C++** with data structures and low-level memory management. However, to better support future stages such as:

* Connecting the blockchain to **REST APIs**
* Simulating a **Bitcoin node** with P2P networking

I decided to create a **modular and scalable version in Node.js** as well.

I have also implemented a **Proof of Work mining mechanism** in both the C++ and Node.js versions to simulate mining by requiring block hashes to meet a certain difficulty level.

---

## Project Structure

```
.
├── blockchain.cpp                # C++ version of blockchain
├── blockchain_nodejs/           # Node.js version
│   ├── index.js
│   ├── package.json
│   └── src/
│       ├── blockchain/
│       │   ├── Block.js
│       │   ├── Blockchain.js
│       │   └── index.js
│       ├── cli/
│       │   └── cli.js
│       └── utils/
│           └── hash.js
```

---

## C++ Blockchain

### Dependencies

* C++11 or higher
* `g++` compiler

### Setup

Install dependencies:

```bash
sudo apt install libssl-dev
```

### Compile and Run

```bash
g++ blockchain.cpp -o blockchain -lssl -lcrypto
./blockchain
```

This will launch a user-interactive CLI where you can:

* Add new blocks with transaction data
* Print the entire blockchain
* Validate the integrity of the chain
* Simulate Proof of Work mining

---

## Node.js Blockchain (Recommended for API + P2P)

### Located in: `blockchain_nodejs/`

### Setup

Install dependencies:

```bash
cd blockchain_nodejs
npm install
```

### Run the Blockchain CLI

```bash
npm run start
```

This will launch a user-interactive CLI where you can:

* Add new blocks with transaction data
* Print the entire blockchain
* Validate the integrity of the chain
* Simulate Proof of Work mining

---

## Credits

This project is developed as part of the **Chain Rxn - BIB Summer Bootcamp 2025**.

---

## Contact

**Goutam Halder**
M.Tech CSE, IIT Bhilai
Email: [goutamhald@iitbhilai.ac.in](mailto:goutamhald@iitbhilai.ac.in)
GitHub: [@goutam363](https://github.com/goutam363)
