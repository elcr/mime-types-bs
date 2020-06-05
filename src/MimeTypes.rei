let types: Js.Dict.t(string);
let extensions: Js.Dict.t(array(string));
let contentType: string => option(string);
let lookup: string => option(string);
let extension: string => option(string);
let charset: string => option(string);
