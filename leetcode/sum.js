function getCombBySum(array, sum, tolerance, targetCount) {
    var util = {
        /*
          get combination from array
          arr: target array
          num: combination item length
          return: one array that contain combination arrays
        */
        /*获取所有的可能组合
        如果是[1,2,3,4,5]取出3个 
        那么可能性就有10种 C(5,3)= C(5,2) 不懂的恶补高二数学排列?
        不用翻书了 给个公式 
        全排列  P(n,m)=n!/(n-m)!
        组合排列 C(5,2)=5!/2!*3!=5*4*3*2*1/[(2*1)*(3*2*1)]=10
        这是使用了循环加递归做出了组合排序
        */
        getCombination: function (arr, num) {
            var r = [];
            (function f(t, a, n) {
                if (n == 0) {
                    return r.push(t);
                }
                for (var i = 0, l = a.length; i <= l - n; i++) {
                    f(t.concat(a[i]), a.slice(i + 1), n - 1);
                }
            })([], arr, num);
            return r;
        },
        // take array index to a array
        // 获取数组的索引
        getArrayIndex: function (array) {
            var i = 0,
                r = [];
            for (i = 0; i < array.length; i++) {
                r.push(i);
            }

            return r;
        }
    }, logic = {
        // sort the array,then get what's we need
        //  获取数组中比sum小的数
        init: function (array, sum) {
            // clone array
            var _array = array.concat(),
                r = [],
                i = 0;
            // sort by asc
            _array.sort(function (a, b) {
                return a - b;
            });
            // get all number when it's less than or equal sum
            for (i = 0; i < _array.length; i++) {
                if (_array[i] <= sum) {
                    r.push(_array[i]);
                } else {
                    break;
                }
            }

            return r;
        },
        // important function
        core: function (array, sum, arrayIndex, count, r) {
            var i = 0,
                k = 0,
                combArray = [],
                _sum = 0,
                _cca = [],
                _cache = [];

            if (count == _returnMark) {
                return;
            }
            // get current count combination
            // 这里排序的不是原来的数组,而是求的索引后的数组

            combArray = util.getCombination(arrayIndex, count);
            for (i = 0; i < combArray.length; i++) {
                _cca = combArray[i];
                _sum = 0;
                _cache = [];
                // calculate the sum from combination
                for (k = 0; k < _cca.length; k++) {
                    _sum += array[_cca[k]];
                    _cache.push(array[_cca[k]]);
                }
                if (Math.abs(_sum - sum) <= _tolerance) {
                    r.push(_cache);
                }
            }
            logic.core(array, sum, arrayIndex, count - 1, r);
        }

    },
        r = [],
        _array = [],
        _targetCount = 0,
        _tolerance = 0,
        _returnMark = 0;

    // check data
    _targetCount = targetCount || _targetCount;
    _tolerance = tolerance || _tolerance;

    _array = logic.init(array, sum);
    if (_targetCount) {
        _returnMark = _targetCount - 1;
    }

    logic.core(_array, sum, util.getArrayIndex(_array), (_targetCount || _array.length), r);

    return r;
}
