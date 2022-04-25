class Enemy{
public:
	Enemy(){
	private String name;
	private double damage;
	}
	
	void attackPlayer();
	void setDamage(double);
	double getDamage();
	
}
class MeleeEnemy :public Enemy{
public:
	MeleeEnemy() : Enemy(){
		void setname(String);
		String getName();

		}
}
class MagicEnemy :public Enemy{
public:
	MagicEnemy() : Enemy(){
		void setName(String);
		String getName();
	}
}

class RangedEnemy :public Enemy{
public:
	RangedEnemy() : Enemy(){
		void setName(String);
		String getName();

	}
}

class EnemyFactory{
	public Enemy makeEnemy(int);
	enemyN = new EnemyFactory;
	return new Enemy();
}

class game{

int main(){
	MagicEnemy();
	RangedEnemy();
	MaleeEnemy();
	Enemy();
	
	return 0;
 }
}