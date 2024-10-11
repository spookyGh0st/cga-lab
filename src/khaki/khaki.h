// #include <Fastor/Fastor.h>

constexpr inline size_t binom(size_t n, size_t k) noexcept
{
    return
            (        k> n  )? 0 :          // out of range
            (k==0 || k==n  )? 1 :          // edge
            (k==1 || k==n-1)? n :          // first
            (     k+k < n  )?              // recursive:
            (binom(n-1,k-1) * n)/k :       //  path to k=1   is faster
            (binom(n-1,k) * n)/(n-k);      //  path to k=n-1 is faster
}

template <typename T, std::size_t n, std::size_t k>
class form {
    std::array<double,binom(n,k)> data;
};

template <typename T, std::size_t n, std::size_t k>
form<T,n, n-k> hodge_star(form<T,n,k>) {
    return form<T,n, n-k>();
}

template <typename T>
class field{
public:
    T operator()() {
        return T();
    }
};


using fform0k3d = form<float,3,0>;
using fform1k3d = form<float,3,1>;
using fform2k3d = form<float,3,2>;
using fform3k3d = form<float,3,3>;
using diff_fform0k3d =field<fform0k3d>;

int compileTest(){
    fform0k3d a = fform0k3d();
    fform3k3d b = hodge_star(a);
    diff_fform0k3d c = diff_fform0k3d();
    return 1;
}