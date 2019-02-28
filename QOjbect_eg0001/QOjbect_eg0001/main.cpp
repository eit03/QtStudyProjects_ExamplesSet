#include <QObject>


class Object : public QObject
{
	Q_OBJECT
	Q_PROPERTY(char* name READ name WRITE setName NOTIFY nameChanged)

private:
	const char* prove_;
	char name_[50];

public:
	explicit Object() : prove_("I am me!")
	{
		Q_UNUSED(prove_);
		name_[0] = '\0';
	}
};

int main()
{
	Object obj;
	obj.objectName();
	return 0;
}
