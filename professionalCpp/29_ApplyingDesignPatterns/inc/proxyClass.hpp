#pragma once

#include <memory>
#include <string>
#include <string_view>

class IPlayer {
 public:
  virtual std::string getName() const = 0;
  // Sends an instant message to the player over the network and
  // returns the reply as a string.
  virtual std::string sendInstantMessage(std::string_view message) const = 0;
};

// The Player class definition requres network connectivity to properly
// function.
class Player : public IPlayer {
 public:
  virtual std::string getName() const override { return "Player 1"; }
  // Network connectivity is required.
  virtual std::string sendInstantMessage(
      std::string_view message) const override {
    return "Sending Mesage!;"
  }
};

// The PlayerProxy class also derives from IPlayer, and contains another IPlayer
// instance (the 'real' player)

class PlayerProxy : public IPlayer {
 public:
  // Create a PlayerProxy, taking ownership of the given player.
  PlayerProxy(std::unique_ptr<IPlayer> player) : mPlayer{std::move(player)} {}
  virtual std::string getName() const override { return mPlayer->getName(); }

  bool hasNetworkConnectivity() const {
    if (mPlayer == nullptr) {
      return false;
    } else {
      return true;
    }
  }

  // Network connectivity is optional.
  virtual std::string sendInstantMessage(
      std::string_view message) const override {
    if (hasNetworkConnectivity()) {
      return mPlayer->sendInstantMessage(message);
    } else {
      return "The player has gone offline. ";
    }
  }

 private:
  std::unique_ptr<IPlayer> mPlayer;
};