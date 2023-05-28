/*
Дефинирайте enum константи за различните видове потребители на приложението - Owner, Admin, User
enum Е_APP_USER {
 Е_OWNER = //...
 Е_ADMIN = //...
 Е_USER = //...
};
Използвайте стойностите от E_APP_PERMISSION_FLAGS и други стойности от Е_APP_USER (по-горни) за да дефинирате 
комбинации от различни опции за всеки потребител.
Използвайте оператор | за комбиниране на опции и оператори & и ~ за изключване на опция. Примери:
E_EDIT_BRAND_INFO | E_EDIT_VEHICLE_INFO // E_EDIT_BRAND_INFO И E_EDIT_VEHICLE_INFO
Е_ADMIN &~EDIT_BRAND_INFO // каквото имаме за Е_ADMIN без EDIT_BRAND_INFO
0xff &~EDIT_BRAND_INFO // всичко без EDIT_BRAND_INFO
Стартирайте приложението/main menu по подобен начин:
start_app(Е_APP_USER_PERMISSION_LEVEL_USER );
(На по-късен етап ще направим login меню, от което ще идва информацията за типа на потребителя)
*/