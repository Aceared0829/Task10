// 声明一个名为Circle的模块，使其可被其他源文件导入
export module Circle;

// 定义PI常量，值为3.1415926
#define PI 3.1415926

// 引入格式化输出相关的头文件
#include <format>
// 引入输入输出流前向声明的头文件
#include <iosfwd>

// 导出Point结构体，使其对导入此模块的代码可见
export struct Point
{
    double X;  // X坐标，使用double类型提供浮点精度
    double Y;  // Y坐标，使用double类型提供浮点精度
    
    // 构造函数：接受x和y坐标初始化Point对象
    Point(double x, double y) : X(x), Y(y) {}
    
    // 默认构造函数：将坐标初始化为原点(0,0)
    Point() : X(0), Y(0) {}
    
    // 析构函数：不执行特殊操作，可以省略
    ~Point(){}
    
    // 获取X坐标的常量成员函数，使用后置返回类型语法
    auto getX() const -> double {return X;}
    
    // 获取Y坐标的常量成员函数，使用后置返回类型语法
    auto getY() const -> double {return Y;}
    
    // 声明输出流运算符<<的友元函数，允许直接输出Point对象
    friend auto operator<<(std::ostream &os, const Point &p) -> std::ostream &;
};

// 实现输出流运算符，以"(x,y)"格式输出Point对象
auto operator<<(std::ostream& os, const Point& p) -> std::ostream&
{
    os<<std::format("({},{})",p.X,p.Y);  // 使用format格式化输出
    return os;   // 返回输出流引用，允许链式调用
}

// 导出Circle类，使其对导入此模块的代码可见
export class Circle
{
private:
    Point center;  // 圆心坐标，使用Point类型
    double radius; // 半径，使用double类型
public:
    // 构造函数：接受圆心坐标(x,y)和半径r
    Circle(double x,double y,double r):center(x,y),radius(r){}
    
    // 默认构造函数：创建一个圆心在原点、半径为1的单位圆
    Circle():center(0,0),radius(1){}
    
    // 析构函数：不执行特殊操作，可以省略
    ~Circle(){}
    
    // 获取圆心的常量成员函数声明
    auto getCenter() const -> Point;
    
    // 获取半径的常量成员函数声明
    auto getRadius() const -> double;
    
    // 计算圆面积的常量成员函数声明
    auto getArea() const -> double;
};

// 实现getCenter函数，返回圆心坐标
export auto Circle::getCenter() const -> Point
{
    return center;
}

// 实现getRadius函数，返回圆的半径
export auto Circle::getRadius() const -> double
{
    return radius;
}

// 实现getArea函数，计算并返回圆的面积
export auto Circle::getArea() const -> double
{
    return radius * radius * PI;  // 面积公式：πr²
}