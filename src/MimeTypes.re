module StringBooleanUnion: {
    type t;

    type case =
        | String(string)
        | Boolean(bool);

    let classify: t => case;
} = {
    [@unboxed]
    type t =
        | Any('a): t;

    type case =
        | String(string)
        | Boolean(bool);

    let classify = (Any(value)) =>
        Js.Types.test(value, String)
            ? String(value |> Obj.magic)
            : Boolean(value |> Obj.magic);
};


[@bs.module "mime-types"]
external types: Js.Dict.t(string) = "types";


[@bs.module "mime-types"]
external extensions: Js.Dict.t(array(string)) = "extensions";


[@bs.module "mime-types"]
external _contentType: string => StringBooleanUnion.t = "contentType";


[@bs.module "mime-types"]
external _lookup: string => StringBooleanUnion.t = "lookup";


[@bs.module "mime-types"]
external _extension: string => StringBooleanUnion.t = "extension";


[@bs.module "mime-types"]
external _charset: string => StringBooleanUnion.t = "charset";


let _wrapUnionReturn = (func, value) =>
    switch (value |> func |> StringBooleanUnion.classify) {
        | String(value) => Some(value)
        | Boolean(_) => None
    };


let contentType = _wrapUnionReturn(_contentType);
let lookup = _wrapUnionReturn(_lookup);
let extension = _wrapUnionReturn(_extension);
let charset = _wrapUnionReturn(_charset);
