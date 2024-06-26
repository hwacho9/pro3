#include <iostream>
#include <vector>

inline int abs(int x) { return 0 <= x ? x : -x; }

class canvas
{
public:
    canvas(int sx, int sy);
    ~canvas();
    void clear();
    void set(int x, int y);
    void print(std::ostream &os);

private:
    int size_x;
    int size_y;
    char **p;
};

std::ostream &operator<<(std::ostream &os, canvas &c)
{
    c.print(os);
    return os;
}

canvas::canvas(int sx, int sy) : size_x(sx), size_y(sy)
{
    p = new char *[size_x];
    for (int x = 0; x < size_x; x++)
        p[x] = new char[size_y];
    this->clear();
}

canvas::~canvas()
{
    for (int x = 0; x < size_x; x++)
        delete[] p[x];
    delete[] p;
}

void canvas::clear()
{
    for (int x = 0; x < size_x; x++)
    {
        for (int y = 0; y < size_y; y++)
        {
            p[x][y] = ' ';
        }
    }
}

void canvas::set(int x, int y)
{
    if (0 <= x && x < size_x && 0 <= y && y < size_y)
        p[x][y] = 'X';
}

void canvas::print(std::ostream &os)
{
    os << '+';
    for (int x = 0; x < size_x; x++)
    {
        os << '-';
    }
    os << '+' << std::endl;
    for (int y = size_y - 1; 0 <= y; y--)
    {
        os << '|';
        for (int x = 0; x < size_x; x++)
        {
            os << p[x][y];
        }
        os << '|' << std::endl;
    }
    os << '+';
    for (int x = 0; x < size_x; x++)
    {
        os << '-';
    }
    os << '+' << std::endl;
}

class obj
{
public:
    obj(int x, int y, const std::string &t);
    virtual ~obj();
    void move(int ix, int iy);
    virtual void draw(canvas &c) = 0;

public:
    int px,
        py;
    std::string type;
};

obj::obj(int x, int y, const std::string &t) : px(x), py(y), type(t) {}

obj::~obj() {}

void obj::move(int ix, int iy)
{
    px += ix;
    py += iy;
}

void obj::draw(canvas &c) {}

class point : public obj
{
public:
    point(int x, int y);
    ~point();
    void draw(canvas &c);
};

point::point(int x, int y) : obj(x, y, "point") {}

point::~point() {}

void point::draw(canvas &c)
{
    c.set(px, py);
}

class rectangle : public obj
{
public:
    rectangle(int x, int y, int w, int h);
    ~rectangle();
    void draw(canvas &c);

private:
    int w, h;
};

rectangle::rectangle(int x, int y, int w, int h) : obj(x, y, "rectangle"), w(w), h(h) {}

rectangle::~rectangle() {}

void rectangle::draw(canvas &c)
{
    for (int i = px; i < px + w; i++)
    {
        for (int j = py; j < py + h; j++)
        {
            c.set(i, j);
        }
    }
}

class diamond : public obj
{
public:
    diamond(int x, int y, int r);
    ~diamond();
    void draw(canvas &c);

private:
    int radius;
};

diamond::diamond(int x, int y, int r) : obj(x, y, "diamond"), radius(r) {}

diamond::~diamond() {}

void diamond::draw(canvas &c)
{
    if (0 <= radius)
    {
        for (int r = -radius; r <= radius; r++)
        {
            int h = radius - abs(r);
            for (int s = -h; s <= h; s++)
            {
                c.set(px + r, py + s);
            }
        }
    }
}

int main(void)

{
    std::vector<obj *> vec;

    // 配列に図形要素を放り込む
    vec.push_back(new point(0, 0));
    vec.push_back(new point(17, 9));
    vec.push_back(new point(19, 2));
    vec.push_back(new rectangle(2, 1, 3, 2));
    vec.push_back(new rectangle(7, 7, 6, 2));
    vec.push_back(new diamond(2, 7, 2));
    vec.push_back(new diamond(15, 3, 4));

    canvas c(20, 10);
    // まとめて描画する
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i]->type == "point")
            ((point *)vec[i])->draw(c);
        else if (vec[i]->type == "rectangle")
            ((rectangle *)vec[i])->draw(c);
        else if (vec[i]->type == "diamond")
            ((diamond *)vec[i])->draw(c);
    }
    std::cout << c;

    // まとめて移動する
    for (int i = 0; i < vec.size(); i++)
        vec[i]->move(4, 2);
    c.clear();

    // まとめて描画する
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i]->type == "point")
            ((point *)vec[i])->draw(c);
        else if (vec[i]->type == "rectangle")
            ((rectangle *)vec[i])->draw(c);
        else if (vec[i]->type == "diamond")
            ((diamond *)vec[i])->draw(c);
    }
    std::cout << c;

    // まとめてdelete
    for (int i = 0; i < vec.size(); i++)
        delete vec[i];
    return 0;
}
