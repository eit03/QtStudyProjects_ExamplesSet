#include <QObject>


class Object : public QObject
{
private:
    const char prove_[sizeof("I am me!")];

public:
    explicit Object() : prove_("I am me!") { Q_UNUSED(prove_); }
};

int main()
{
    Object obj;
    obj.objectName();
    return 0;
}
