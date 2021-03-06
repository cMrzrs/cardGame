#ifndef PLAYER_0
#define PLAYER_0

class Player;
class Province;

#include "basicHeader.hpp"

/* ================================================================= */
class Province
{
  bool isBroken; /* Initialize as false */

  BlackCardPtr card;

public:

  Province(BlackCardPtr);

  bool checkBroken() const { return isBroken; }

  void setBroken() { isBroken = true; }
  void setCard(BlackCardPtr bc) { card = bc ; }

  BlackCardPtr getCard() const { return card; }

  void print() const;

};

/* ================================================================= */

class Player
{
  const std::string userName;

  StrongHoldPtr strongHold;

  uint16_t honor;
  
  uint16_t activeProvinces;

  FateDeckPtr    fateDeck;
  DynastyDeckPtr dynastyDeck;

  HandPtr hand;
  ArmyPtr army;

  HoldingListPtr  holdings;
  ProvinceListPtr provinces;

public:

  Player(const std::string & userName );

  const std::string& getUserName() const { return userName; }

  uint16_t getHonor()        const { return honor; }
  uint16_t getProvincesNum() const { return activeProvinces; }
  uint16_t getCurrMoney()    const;

  void decreaseProvinceNum() { --activeProvinces; }
  void increaseProvinceNum() { ++activeProvinces; }
  
  FateDeckPtr    getFateDeck()    const { return fateDeck; }
  DynastyDeckPtr getDynastyDeck() const { return dynastyDeck; }
  
  HandPtr getHand() const { return hand; }
  ArmyPtr getArmy() const { return army; }

  ProvinceListPtr getProvinces() const { return provinces; }
  HoldingListPtr  getHoldings()  const { return holdings; }

  StrongHoldPtr getStrongHold()  const { return strongHold; }

  void setFateDeck   (FateDeckPtr    fDeck) { fateDeck    = fDeck; }
  void setDynastyDeck(DynastyDeckPtr dDeck) { dynastyDeck = dDeck; }
  void setStrongHold (StrongHoldPtr strH) { strongHold = strH;  honor = strH->getInitHonor(); }

  void print()              const;
  void printHoldings()      const;
  void printArmy()          const;
  void printArena()         const;
  void printAvailableArmy() const;
  void printHand()          const;
  void printProvinces()     const;
  void printStatistics()    const;

  bool makePurchase (int32_t cost ); /* Tap Holdings until you cover the required cost */
    /* Returns true if the purchase is successfull */
  void cleanup(); /* Removes 1) Dead personalities from army 
                             2) Detached GreenCards */

  BlackCardPtr drawBlackCard (void);
  GreenCardPtr drawFateCard (void);
};  
/* ================================================================= */

#endif