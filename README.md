# 重构

## 如何使用

before目录是重构前的代码, after是重构后的代码

## 重构都使用哪些方法

字段上移, 提取公共类

## 重构细节

- 1 构造测试
- 2 提取公共类, 字段上移

### 构造测试

有功能可知, 业务主要负责的构造路线, 对不同的车执行操作命令. 需要遍历所有的车型对所有的指令进行遍历.

```c++
// after/car/driver_test.cpp
TEST(driver_test, nocar);
TEST(driver_test, bmw);
TEST(driver_test, benz);
TEST(driver_test, audi)
```

### 提取公共类

针对cars对象抽象公共类, 所有车型都包含的方法抽象出来, 作为父类

```c++
class Car
{
public:
    std::string start();
    std::string stop();
    std::string right();
    std::string straight(int distance);
    std::string left();

private:
    std::string _name = "";
};

class BMW : public Car
{
public:
    std::string hiBMW();

private:
    std::string _name = "bmw";
};

class Audi
{
private:
    std::string _name = "audi";
};

class Benz
{
public:
    std::string transform();

private:
    std::string _name = "benz";
};
```

### 提取默认行为

提取默认行为, 抽象为不存在的车型(NoCar)

```c++
//car/driver.cpp
...
else
{
    ret.push_back("driver don't kwon how to start!");
}
...
else
{
    ret.push_back("driver don't kwon how to stop!");
}
...
else
{
    ret.push_back("driver don't kwon how to turn right!");
}
...
else
{
    ret.push_back("driver don't kwon how to turn left!");
}
...
else
{
    ret.push_back("driver don't kwon how to go straight!");
}
...
```

创建NoCar对象, 继承Car. 父类car是较为稳定, 子类可以根据新增类型跟新频率较高

```c++
class NoCar : public Car
{
public:
    virtual std::string name();
    virtual std::string hiBMW();
    virtual std::string transform();
    virtual std::string start();
    virtual std::string stop();
    virtual std::string right();
    virtual std::string straight(int distance);
    virtual std::string left();
};

// 同时在 Driver 中用 Car* 替换 
// CarType _car;
// Benz _benz;
// Audi _audi;
// BMW _bmw;
// 使用 setCar(Car*) 替换
// void setBenz(Benz benz);
// void setAudi(Audi audi);
// void setBmw(BMW bmz);
class Driver
{
public:
    std::vector<std::string> drive(Route route);
    void setCar(Car *car);
    Driver(std::string name);

private:
    Car *_car;
    std::string _name;
};

// 同时 Driver::drive() 中根据 carType 的判断可使用泛型做进一步优化
std::vector<std::string> Driver::drive(Route route)
{
    std::vector<std::string> ret;
    for (Move move : route)
    {
        if (move.action == Action::start)
        {
            ret.push_back(_car->start());
        }
        else if (move.action == Action::stop)
        {
            ret.push_back(_car->stop());
        }
        else if (move.action == Action::turn)
        {
            if (move.direction == Direction::left)
            {
                ret.push_back(_car->left());
            }
            else
            {
                ret.push_back(_car->right());
            }
        }
        else if (move.action == Action::straight)
        {
            ret.push_back(_car->straight(move.distance));
        }
        else if (move.action == Action::hi)
        {
            if (typeid(*_car) == typeid(NoCar))
            {
                ret.push_back(dynamic_cast<NoCar *>(_car)->hiBMW());
            }
            else if (typeid(*_car) == typeid(BMW))
            {
                ret.push_back(dynamic_cast<BMW *>(_car)->hiBMW());
            }
        }
        else if (move.action == Action::transform)
        {
            if (typeid(*_car) == typeid(NoCar))
            {
                ret.push_back(dynamic_cast<NoCar *>(_car)->transform());
            }
            else if (typeid(*_car) == typeid(Benz))
            {
                ret.push_back(dynamic_cast<Benz *>(_car)->transform());
            }
        }
    }
    return ret;
}
```

### 进一步 函数提取

```c++
// 对于 car 的 right() 和 left() 抽象为 turn(Direction)
virtual std::string Car::right();
virtual std::string Car::left();
// 可将 std::vector<std::string> Driver::drive(Route route) 的 
// move.action == Action::turn 分支 进一步合并

else if (move.action == Action::turn)
{
    ret.push_back(_car->turn(move.direction));
}
```

### 更进一步 函数提取

```c++
// 对 Driver::drive 的 for 循环做进一步抽象
std::vector<std::string> Driver::drive(Route route) {
    std::vector<std::string> ret;
    for (Move move : route)
    {
        ...
    }
}

// 抽象得到函数
std::string Driver::move(Move m)
{
    if (m.action == Action::start)
    {
        return _car->start();
    }
    else if (m.action == Action::stop)
    {
        return _car->stop();
    }
    else if (m.action == Action::turn)
    {
        return _car->turn(m.direction);
    }
    else if (m.action == Action::straight)
    {
        return _car->straight(m.distance);
    }
    else if (m.action == Action::hi)
    {
        if (typeid(*_car) == typeid(NoCar))
        {
            return dynamic_cast<NoCar *>(_car)->hiBMW();
        }
        else if (typeid(*_car) == typeid(BMW))
        {
            return dynamic_cast<BMW *>(_car)->hiBMW();
        }
    }
    else if (m.action == Action::transform)
    {
        if (typeid(*_car) == typeid(NoCar))
        {
            return dynamic_cast<NoCar *>(_car)->transform();
        }
        else if (typeid(*_car) == typeid(Benz))
        {
            return dynamic_cast<Benz *>(_car)->transform();
        }
    }
    // 对于 m.action == Action::hi 以及 m.action == Action::transform 未对所有车型都可操作
    // 所以会进入当前分支
    throw(std::exception());
    return "";
}
```

### 为 合并分支 做准备

```c++
// 继续对 move 方法进行拆分 对于每种 Action 操作 做方法抽象
std::string Driver::start(Move m)
{
    return _car->start();
}

std::string Driver::stop(Move m)
{
    return _car->stop();
}

std::string Driver::turn(Move m)
{
    return _car->turn(m.direction);
}

std::string Driver::straight(Move m)
{
    return _car->straight(m.distance);
}

std::string Driver::hi(Move m)
{
    if (typeid(*_car) == typeid(NoCar))
    {
        return dynamic_cast<NoCar *>(_car)->hiBMW();
    }
    else if (typeid(*_car) == typeid(BMW))
    {
        return dynamic_cast<BMW *>(_car)->hiBMW();
    }
    throw(std::exception());
    return "";
}

std::string Driver::transform(Move m)
{
    if (typeid(*_car) == typeid(NoCar))
    {
        return dynamic_cast<NoCar *>(_car)->transform();
    }
    else if (typeid(*_car) == typeid(Benz))
    {
        return dynamic_cast<Benz *>(_car)->transform();
    }
    throw(std::exception());
    return "";
}

std::string Driver::move(Move m)
{
    if (m.action == Action::start)
    {
        return start(m);
    }
    else if (m.action == Action::stop)
    {
        return stop(m);
    }
    else if (m.action == Action::turn)
    {
        return turn(m);
    }
    else if (m.action == Action::straight)
    {
        return straight(m);
    }
    else if (m.action == Action::hi)
    {
        return hi(m);
    }
    else if (m.action == Action::transform)
    {
        return transform(m);
    }
    throw(std::exception());
    return "";
}

```

### 合并分支

```c++

class Driver
{
public:
    std::string (Driver::*action)(Move);
    template <typename T>
    T getAction(Move m);
    std::vector<std::string> drive(Route route);
    void setCar(Car *car);
    std::string move(Move m);
    std::string start(Move m);
    std::string stop(Move m);
    std::string turn(Move m);
    std::string straight(Move m);
    std::string hi(Move m);
    std::string transform(Move m);
    Driver(std::string name);

private:
    Car *_car;
    std::string _name;
};

template <typename T>
T Driver::getAction(Move m)
{
    if (m.action == Action::start)
    {
        return &Driver::start;
    }

    if (m.action == Action::stop)
    {
        return &Driver::stop;
    }

    if (m.action == Action::straight)
    {
        return &Driver::straight;
    }

    if (m.action == Action::turn)
    {
        return &Driver::turn;
    }

    if (m.action == Action::hi)
    {
        return &Driver::hi;
    }

    if (m.action == Action::transform)
    {
        return &Driver::transform;
    }

    assert(false);
    return nullptr;
}

std::string Driver::move(Move m)
{
    auto next = getAction<decltype(action)>(m);
    return (this->*next)(m);
}

```
