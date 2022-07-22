#ifndef HAND_H
#define HAND_H

/**
 * @file hand.h
 * @brief Файл з описом функцій класів "карта" та "рука".
 * Клас "карта": перерахування, конструктор, деструктор, отримання 
 * значення карти, перевертання карти та оператор виводу.
 * Клас "рука": конструктор, деструктор, додавання карти в руку,
 * очищення руки від карт та отримання суми очок карт в руці.
 *
 * @author Khelemendyk D.
 * @date 15-july-2022
 * @version 0.1
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Клас "карта". Відображає ранг та масть карти.
 */
class Card {
    public:
	/**
	 * Перерахування "ранг". Представляє індекс карти.
	 */
	enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	/**
	 * Перерахування "масть". Представляє масть карки.
	 */
	enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	Card(Rank r = ACE, Suit s = SPADES, bool ifu = true);
	~Card();
	/**
	 * Отримання значення карти.
	 *
	 * Функція перевіряє чи відкрита карта, якщо так - повертає 
	 * її значення.
	 * @return значення карти від 1 до 11.
	 */
	int getValue() const;

	/**
	 * Перевертання карти.
	 *
	 * Функція перевертає карту: карта, що лежить сорочкою вгору, 
	 * перевертається вниз і навпаки.
	 */
	void flipCard();

	/**
	 * Перегрузка оператора виводу.
	 *
	 * Функція відправляє об'єкт типа Card в стандартний поток виводу.
	 * Якщо карта не схована - друкує її ранг та масть, інакше 
	 * виводить "ХХ".
	 */
	friend ostream &operator<<(ostream &os, const Card &card);

    private:
	Rank rank;
	Suit suit;
	bool isFaceUp;
};
/**
 * Клас "рука". Відображає руку, яка тримає карти.
 */
class Hand {
    public:
	Hand();
	virtual ~Hand();
	/**
	 * Додавання карти в руку.
	 *
	 * Функція отримує карту pCard та додає її в вектор cards.
	 * @param pCard карта, об'єкт класа Card, яку потрібно додати 
	 * в руку.
	 */
	void addCard(Card *pCard);

	/**
	 * Очищення руки від карт.
	 *
	 * Функція проходить по вектору, звільнює зайняту пам'ять. 
	 * Далі звільнює вектор показників. 
	 */
	void clearHand();
	
	/**
	 * Отримання суми очок карт в руці гравця.
	 *
	 * Функція рахує кількість очок, привласнюючи тузу значення 
	 * 1 або 11 залежно від ситуації.
	 * @return загальну кількість очок в руці гравця.
	 */
	int getTotal() const;

    protected:
	vector<Card *> cards;
};
#endif