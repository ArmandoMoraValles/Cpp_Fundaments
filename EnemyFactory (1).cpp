#include <iostream>
#include <string>

class Enemy{ //clase abstracta
public:
	Enemy(){}
	std::string getTypeEnemy(){ return this->tipoEnemigo;}
protected:
	std::string tipoEnemigo;
	std::string nombre;
	double damage;
	
};

class MeleeEnemy :public Enemy{
public:
	MeleeEnemy() : Enemy(){
		std::cout<<"Introduzca el damage del personaje\n";
		std::cin>>damage;
		std::cin.ignore();
		std::cout<<"Introduzca el nombre del enemigo\n";
		std::getline(std::cin,nombre);
	    tipoEnemigo= "Enemigo Melee";
		std::cout <<"Se enfrentara a un enemigo tipo Melee\n";
		std::cout <<"El nombre del enemigo es "<<nombre<<" y su damage es de "<<damage<<" puntos\n";
		}
};
class MagicEnemy :public Enemy{
public:
	MagicEnemy() : Enemy(){
		std::cout<<"Introduzca el damage del personaje\n";
		std::cin>>damage;
		std::cin.ignore();
		std::cout<<"Introduzca el nombre del enemigo\n";
		std::getline(std::cin,nombre);
		tipoEnemigo = "Enemigo Magic";
		std::cout << "Se enfrentara a un enemigo tipo Magic\n";
		std::cout <<"El nombre del enemigo es "<<nombre<<" y su damage es de "<<damage<<" puntos\n";
	}
};

class RangedEnemy :public Enemy{
public:
	RangedEnemy() : Enemy(){
		std::cout<<"Introduzca el damage del personaje\n";
		std::cin>>damage;
		std::cin.ignore();
		std::cout<<"Introduzca el da�o del personaje\n";
		std::cout<<"Introduzca el nombre del enemigo\n";
		std::getline(std::cin,nombre);
		tipoEnemigo = "Enemigo Ranged";
		std::cout<<"Se enfrentara a un enemigo tipo Ranged\n";
		std::cout <<"El nombre del enemigo es "<<nombre<<" y su damage es de "<<damage<<" puntos\n";
	}
};

class TypeFactory{
public:
	Enemy* getType(){
		int op=0;
		
		std::cout<<"1.Melee \n";
		std::cout<<"2.Magic \n";
		std::cout<<"3.Ranged \n";
		std::cout<<"Elija una opcion:";
		std::cin>>op;
		
		switch(op){
			case 1:
				type = new MeleeEnemy;
				break;
			case 2:
				type = new MagicEnemy;
				break;
			case 3:
				type = new RangedEnemy;
				break;
			default:
				type = NULL;
				break;
		}
		
		return type;
	}
private:
	Enemy* type;
};

int main(){
	
	TypeFactory FabricaTipo;
	Enemy* tipoSeleccionado;
	
	tipoSeleccionado = FabricaTipo.getType();
	
	if(tipoSeleccionado != NULL){
		std::cout << tipoSeleccionado->getTypeEnemy() << "\n";
	}else{
		std::cout<<"El tipo de enemigo no existe\n";
	}
	return 0;
}
//e
