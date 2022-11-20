#pragma once

/**
 * @brief Classe d'Observer, pour notifier un observer via la fonction update d'un changement
 * @author SUARD GaetanCLOSSON Jules
*/
class Observer {
public:
  virtual ~Observer() {}
  virtual void update() = 0;
};
/**
 * @brief Classe d'un observable, pour faire d'une classe une classe observable, qui possedera des observers
 * @author SUARD GaetanCLOSSON Jules
*/
class Observable {
public:
  virtual ~Observable() {}
  virtual void addObserver(Observer* observer) = 0;
  virtual void removeObserver(Observer* observer) = 0;
  virtual void notifyObserver() const = 0;
};
