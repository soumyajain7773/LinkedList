/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (obj === null) return null;

    if (typeof obj !== "object") {
        return obj;
    }

    let result = Array.isArray(obj) ? [] : {};

    for (let key in obj) {
        let val = compactObject(obj[key]);

        if (Boolean(val)) {
            if (Array.isArray(result)) {
                result.push(val);
            } else {
                result[key] = val;
            }
        }
    }

    return result;
};
