#ifndef IRULAN_VECTOR2_H
#define IRULAN_VECTOR2_H


namespace iru {
    template<typename T>
    class Vector2 {
    public:
        T x, y;

        Vector2() = default;
        Vector2(T x, T y): x(x), y(y){};
    };

    using Vector2i = Vector2<int>;
    using Vector2f = Vector2<float>;
}

#endif //IRULAN_VECTOR2_H
