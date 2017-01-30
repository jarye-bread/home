#pragma once
#include "deck.h"
#include "card.h"
#include "player.h"
#include <random>

bool blackJack(Deck *myDeck, Player *userP, Player *compP, std::random_device &rd);