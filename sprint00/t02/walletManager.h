#pragma once

#include <iostream>
#include <memory>

struct Wallet {
    int a = 444;
    int septims;
};

Wallet* createWallet(int amount);

void destroyWallet(Wallet* wallet);

Wallet* createWallets(int amount);

void destroyWallets(Wallet* wallet);
