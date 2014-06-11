#ifndef SINGLETONTEMPLATE_H
#define SINGLETONTEMPLATE_H

template <typename T>
class Singleton
{
protected:
  // Constructeur/destructeur
  Singleton () { }
  ~Singleton () { std::cout << "destroying singleton." << std::endl; }

public:
  // Interface publique
  static T *getInstance ()
  {
    if (NULL == instance)
      {
        std::cout << "creating singleton." << std::endl;
        instance = new T;
      }
    else
      {
        std::cout << "singleton already created!" << std::endl;
      }

    std::cout<<"Valeure de retour de la fonction : "<<instance<<"\n";
    return (static_cast<T*> (instance));
  }

  static void kill ()
  {
    if (NULL != instance)
      {
        delete instance;
        instance = NULL;
      }
  }

private:
  // Unique instance
  static T *instance;
};

template <typename T>
T *Singleton<T>::instance = NULL;

#endif // SINGLETONTEMPLATE_H
