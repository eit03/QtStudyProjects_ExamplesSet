#pragma once

#include <QObject>
#include <QDebug>
#include <QString>


class Object : public QObject
{
	Q_OBJECT
		Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
		Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

private:
	const char* prove_;
	int age_;
	QString name_;

public:
	explicit Object() : prove_("I am me!"), age_(0)
	{
		Q_UNUSED(prove_);
		connect(this, SIGNAL(ageChanged(int)),
			this, SLOT(onAgeChanged(int)));
		connect(this, SIGNAL(nameChanged(QString)),
			this, SLOT(onNameChanged(QString)));
	}

public:
	int age() { return age_; }
	void setAge(int age)
	{
		if (age_ != age)
		{
			age_ = age;
			emit ageChanged(age);
		}
	}

	QString name() { return name_; }
	void setName(QString name)
	{
		if (name != name_)
		{
			name_ = name;
			emit nameChanged(name);
		}
	}

Q_SIGNALS:
	void ageChanged(int age);
	void nameChanged(QString name);

protected Q_SLOTS:
	void onAgeChanged(int age) 
	{ 
		printf("age changed: %d\n", age);
		qDebug() << "age changed: " << QString("%1").arg(age);
	}
	void onNameChanged(QString name)
	{ 
		printf("name changed: %s\n", name.toUtf8().data());
		qDebug() << "name changed: " << name;
	}
};
