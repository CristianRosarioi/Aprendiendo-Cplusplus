// Generador educativo sin red. Sus propias funciones no forman parte del
// código de nivel inicial que escribe en generados/.
#include <algorithm>
#include <cerrno>
#include <cctype>
#include <cstdio>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#ifdef _WIN32
#include <direct.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#else
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

using namespace std;

struct Opcion {
    int id;
    string motivo;
};

struct Configuracion {
    int id = 0;
    int divisor = 7;
    int inicio = 1;
    int final = 20;
    int umbral = 70;
    int tabla = 5;
    char accion = 'p'; // s: suma, c: cantidad, p: promedio
    char ciclo = 'w';  // w: while, f: for
    bool fijos = false;
    bool incluirInicio = true;
    bool incluirFinal = true;
    bool validar = true;
    bool pares = true;
    bool aprobadas = false;
    bool espacios = true;
    bool distinguir = true;
    bool charFijo = false;
    char buscado = 'a';
    bool categorias[5] = {true, true, true, true, true};
    char vocal = 't'; // t: todas; a/e/i/o/u: una vocal
    string textoDemo = "Sol";
};

const char* NOMBRES[] = {
    "", "Operaciones con dos numeros", "Comparar numeros", "Validar intervalo",
    "Tabla de multiplicar", "Multiplos: suma/cantidad/promedio",
    "Pares o impares: suma/cantidad/promedio", "Clasificar numeros",
    "Promedio de notas", "Primos en intervalo", "Potencia sin pow",
    "Clasificar caracteres", "Contar vocales", "Contar un caracter",
    "Operaciones de string", "Edad, sexo y vocal"
};

const char* ARCHIVOS[] = {
    "", "operaciones", "comparar", "intervalo", "tabla", "multiplos",
    "paridad", "clasificar_numeros", "notas", "primos", "potencia",
    "clasificar_caracteres", "vocales", "buscar_caracter", "cadenas",
    "edad_sexo_vocal"
};

string leer(const string& pregunta) {
    cout << pregunta;
    string linea;
    if (!getline(cin, linea)) throw runtime_error("Entrada terminada. No se guardo ningun archivo.");
    return linea;
}

int entero(const string& pregunta, int minimo, int maximo) {
    while (true) {
        string linea = leer(pregunta);
        istringstream entrada(linea);
        int valor;
        char sobrante;
        if ((entrada >> valor) && !(entrada >> sobrante) &&
            valor >= minimo && valor <= maximo) return valor;
        cout << "Opcion invalida: escriba un entero entre " << minimo
             << " y " << maximo << ".\n";
    }
}

int enteroSugerido(const string& pregunta, int sugerido, int minimo, int maximo) {
    while (true) {
        string linea = leer(pregunta);
        if (linea.empty() && sugerido >= minimo && sugerido <= maximo) return sugerido;
        istringstream entrada(linea);
        int valor;
        char sobrante;
        if ((entrada >> valor) && !(entrada >> sobrante) &&
            valor >= minimo && valor <= maximo) return valor;
        cout << "Numero invalido; rango: " << minimo << ".." << maximo << ".\n";
    }
}

bool siNo(const string& pregunta) {
    while (true) {
        string respuesta = leer(pregunta + " (s/n): ");
        if (respuesta == "s" || respuesta == "S") return true;
        if (respuesta == "n" || respuesta == "N") return false;
        cout << "Escriba s o n.\n";
    }
}

// Sustituye SOLO secuencias conocidas; no borra indiscriminadamente bytes UTF-8.
string normalizar(const string& original) {
    const vector<pair<string, string>> reemplazos = {
        {"Á", "a"}, {"É", "e"}, {"Í", "i"}, {"Ó", "o"}, {"Ú", "u"},
        {"á", "a"}, {"é", "e"}, {"í", "i"}, {"ó", "o"}, {"ú", "u"},
        {"Ü", "u"}, {"ü", "u"}, {"Ñ", "n"}, {"ñ", "n"}
    };
    string salida;
    for (size_t i = 0; i < original.size();) {
        bool encontrado = false;
        for (const auto& r : reemplazos) {
            if (original.compare(i, r.first.size(), r.first) == 0) {
                salida += r.second;
                i += r.first.size();
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            unsigned char byte = static_cast<unsigned char>(original[i++]);
            salida += static_cast<char>(byte < 128 ? std::tolower(byte) : byte);
        }
    }
    return salida;
}

vector<string> palabras(const string& texto) {
    vector<string> resultado;
    string palabra;
    for (unsigned char b : normalizar(texto)) {
        if ((b >= 'a' && b <= 'z') || (b >= '0' && b <= '9')) {
            palabra += static_cast<char>(b);
        } else if (!palabra.empty()) {
            resultado.push_back(palabra);
            palabra.clear();
        }
    }
    if (!palabra.empty()) resultado.push_back(palabra);
    return resultado;
}

bool tiene(const vector<string>& tokens, initializer_list<const char*> variantes) {
    for (const char* v : variantes) {
        if (find(tokens.begin(), tokens.end(), v) != tokens.end()) return true;
    }
    return false;
}

void agregar(vector<Opcion>& opciones, int id, const string& motivo) {
    for (const auto& x : opciones) if (x.id == id) return;
    opciones.push_back({id, motivo});
}

vector<Opcion> proponer(const vector<string>& t) {
    vector<Opcion> r;
    const bool prom = tiene(t, {"promedio", "promediar", "media"});
    const bool sum = tiene(t, {"suma", "sumar", "sumatoria"});
    const bool cont = tiene(t, {"contar", "cuenta", "cantidad", "conteo"});
    if (tiene(t, {"multiplo", "multiplos", "divisibles"}))
        agregar(r, 5, "se mencionan multiplos o divisibilidad");
    if (tiene(t, {"par", "pares", "impar", "impares"}))
        agregar(r, 6, "se mencionan pares o impares");
    if (tiene(t, {"nota", "notas", "calificacion", "calificaciones", "aprobadas"}))
        agregar(r, 8, "se mencionan notas o aprobacion");
    if (tiene(t, {"primo", "primos"})) agregar(r, 9, "se mencionan numeros primos");
    if (tiene(t, {"potencia", "potencias", "exponente", "elevar"}))
        agregar(r, 10, "se menciona potencia o exponente");
    if (tiene(t, {"vocal", "vocales"})) {
        if (tiene(t, {"edad", "sexo", "mujer", "hombre"}))
            agregar(r, 15, "vocal elegida segun edad y sexo");
        else agregar(r, 12, "se mencionan vocales");
    }
    if (tiene(t, {"mayuscula", "mayusculas", "minuscula", "minusculas", "digito", "digitos", "puntuacion", "alfanumerico", "alfanumericos"}))
        agregar(r, 11, "se piden categorias de caracteres");
    if (tiene(t, {"clasificar", "clasificacion"}) &&
        tiene(t, {"caracter", "caracteres", "texto"}))
        agregar(r, 11, "se pide clasificar caracteres de un texto");
    if (tiene(t, {"caracter", "caracteres", "letra", "letras", "apariciones"}) &&
        !tiene(t, {"mayuscula", "mayusculas", "minuscula", "minusculas", "digito", "digitos", "puntuacion", "alfanumerico", "alfanumericos", "vocal", "vocales"}))
        agregar(r, 13, "se busca contar apariciones de un caracter");
    if (tiene(t, {"insertar", "borrar", "subcadena", "cadenas", "string", "erase", "insert"}))
        agregar(r, 14, "se mencionan operaciones sobre string");
    if (tiene(t, {"tabla"})) agregar(r, 4, "se menciona una tabla");
    if (tiene(t, {"comparar", "mayor", "menor", "igual"}) && r.empty())
        agregar(r, 2, "se mencionan comparaciones");
    if (tiene(t, {"operaciones", "aritmeticas", "resta", "division"}) && r.empty())
        agregar(r, 1, "se mencionan operaciones basicas");
    if (tiene(t, {"positivo", "positivos", "negativo", "negativos", "ceros"}))
        agregar(r, 7, "se pide clasificar numeros por su signo");
    if (tiene(t, {"validar", "validacion", "intervalo"}) && r.empty())
        agregar(r, 3, "se menciona validacion de intervalo");
    if (r.empty() && (prom || sum || cont)) {
        if (prom) {
            agregar(r, 5, "promedio de multiplos (filtro sin especificar)");
            agregar(r, 6, "promedio de pares/impares (filtro sin especificar)");
            agregar(r, 8, "promedio de notas (datos sin especificar)");
        } else {
            agregar(r, 5, "suma o conteo en intervalo (filtro sin especificar)");
            agregar(r, 6, "suma o conteo de pares/impares (filtro sin especificar)");
            agregar(r, 7, "conteo de signos en lista (datos sin especificar)");
        }
    }
    return r;
}

int divisorEnTexto(const vector<string>& t) {
    for (size_t i = 0; i + 2 < t.size(); ++i) {
        if ((t[i] == "multiplo" || t[i] == "multiplos" || t[i] == "divisibles") && t[i+1] == "de") {
            istringstream ss(t[i+2]);
            int valor;
            char extra;
            if ((ss >> valor) && !(ss >> extra) && valor >= 1 && valor <= 10000) return valor;
        }
    }
    return 0; // No había divisor explícito; el asistente propondrá 7.
}

string restricciones(const vector<string>& t, int id) {
    vector<string> avisos;
    if (tiene(t, {"ordenar", "ordenamiento", "archivo", "archivos", "vector", "vectores", "recursion", "recursivo", "mediana", "porcentaje", "matriz", "matrices", "factorial"}))
        avisos.push_back("Hay requisitos fuera de estas plantillas (ordenar, archivos, vectores, matrices, mediana, porcentaje o factorial).");
    if (tiene(t, {"while"}) && id != 3 && id != 5 && id != 6)
        avisos.push_back("Se menciona WHILE, pero esta plantilla no ofrece ese ciclo como parametro.");
    if (tiene(t, {"for"}) && (id == 3 || id == 10))
        avisos.push_back("Se menciona FOR, pero esta plantilla usa WHILE.");
    if (tiene(t, {"sin"}) && (tiene(t, {"while", "for", "ciclos", "if"})))
        avisos.push_back("Las prohibiciones de ciclos o condiciones no se interpretan automaticamente.");
    if (id == 5 && tiene(t, {"par", "pares", "impar", "impares"}))
        avisos.push_back("Esta plantilla selecciona multiplos; no combina un filtro adicional par/impar.");
    if (id == 6 && tiene(t, {"multiplo", "multiplos"}))
        avisos.push_back("Esta plantilla filtra paridad; no combina un divisor adicional.");
    if (id == 8 && tiene(t, {"multiplo", "multiplos", "par", "pares"}))
        avisos.push_back("El promedio de notas no aplica filtros de multiplos ni paridad.");
    if (tiene(t, {"promedio", "promediar", "media"}) &&
        id != 5 && id != 6 && id != 8)
        avisos.push_back("Esta plantilla no calcula un promedio.");
    if (tiene(t, {"primo", "primos"}) && id != 9)
        avisos.push_back("Esta plantilla no filtra numeros primos.");
    if (tiene(t, {"vocal", "vocales"}) && id != 12 && id != 15)
        avisos.push_back("Esta plantilla no cuenta vocales como tales.");
    if (tiene(t, {"multiplo", "multiplos", "divisibles"}) && id != 5 && id != 6)
        avisos.push_back("Esta plantilla no filtra multiplos de un divisor.");
    if (tiene(t, {"suma", "sumar", "sumatoria"}) &&
        id != 1 && id != 5 && id != 6 && id != 7)
        avisos.push_back("Esta plantilla no muestra una suma de los datos.");
    if (tiene(t, {"contar", "cuenta", "cantidad", "conteo"}) &&
        id != 5 && id != 6 && id != 7 && id != 11 && id != 12 &&
        id != 13 && id != 15)
        avisos.push_back("Esta plantilla no muestra una cantidad de elementos.");
    string salida;
    for (const string& aviso : avisos) salida += "- " + aviso + "\n";
    return salida;
}

string conflictos(const vector<string>& t, const Configuracion& c) {
    string avisos;
    if ((c.id == 5 || c.id == 6) && !t.empty()) {
        if (tiene(t, {"promedio", "promediar", "media"}) && c.accion != 'p')
            avisos += "- El enunciado pide promedio; elegiste otra operacion.\n";
        if (tiene(t, {"suma", "sumar", "sumatoria"}) && c.accion != 's')
            avisos += "- El enunciado pide suma; elegiste otra operacion.\n";
        if (tiene(t, {"contar", "cuenta", "cantidad", "conteo"}) && c.accion != 'c')
            avisos += "- El enunciado pide conteo; elegiste otra operacion.\n";
        if (c.id == 5 && divisorEnTexto(t) != 0 && c.divisor != divisorEnTexto(t))
            avisos += "- El divisor elegido difiere del numero que aparece tras 'multiplos de'.\n";
        if (tiene(t, {"while"}) && c.ciclo != 'w')
            avisos += "- El enunciado menciona while; elegiste for.\n";
        if (tiene(t, {"for"}) && c.ciclo != 'f')
            avisos += "- El enunciado menciona for; elegiste while.\n";
        if (c.id == 6 && tiene(t, {"impar", "impares"}) && c.pares)
            avisos += "- El enunciado dice impares; elegiste pares.\n";
        if (c.id == 6 && tiene(t, {"par", "pares"}) && !c.pares)
            avisos += "- El enunciado dice pares; elegiste impares.\n";
    }
    return avisos;
}

void menu() {
    cout << "\nPlantillas disponibles:\n";
    for (int i = 1; i <= 15; ++i) cout << i << ". " << NOMBRES[i] << '\n';
}

int escoger(const vector<Opcion>& candidatos) {
    if (candidatos.empty()) {
        cout << "No reconozco ese enunciado con reglas simples. Elija manualmente.\n";
        menu();
        return entero("Plantilla 1-15 (0 cancela): ", 0, 15);
    }
    cout << "Propuestas (no son una interpretacion general del enunciado):\n";
    for (size_t i = 0; i < candidatos.size(); ++i)
        cout << i+1 << ". [" << candidatos[i].id << "] "
             << NOMBRES[candidatos[i].id] << ": " << candidatos[i].motivo << '\n';
    if (candidatos.size() > 1) cout << "Hay varias interpretaciones; escoja expresamente.\n";
    int opcion = entero("Propuesta 1..N (0 abre el menu): ", 0, static_cast<int>(candidatos.size()));
    if (opcion == 0) {
        menu();
        return entero("Plantilla 1-15 (0 cancela): ", 0, 15);
    }
    return candidatos[opcion-1].id;
}

string accionNombre(char accion) {
    if (accion == 's') return "suma";
    if (accion == 'c') return "cantidad";
    return "promedio";
}

void preguntarIntervalo(Configuracion& c, bool permitirCiclo) {
    c.fijos = siNo("¿Extremos fijos en el codigo en vez de leidos al ejecutar?");
    if (c.fijos) {
        c.inicio = entero("Inicio fijo (-10000..10000): ", -10000, 10000);
        c.final = entero("Final fijo (-10000..10000): ", -10000, 10000);
    }
    c.incluirInicio = siNo("¿Incluir el extremo inicial?");
    c.incluirFinal = siNo("¿Incluir el extremo final?");
    c.validar = siNo("¿Exigir inicio < final?");
    if (c.fijos && c.validar) {
        while (c.inicio >= c.final) {
            cout << "Los extremos fijos deben cumplir inicio < final.\n";
            c.inicio = entero("Nuevo inicio: ", -10000, 10000);
            c.final = entero("Nuevo final: ", -10000, 10000);
        }
    }
    if (permitirCiclo) c.ciclo = entero("Ciclo: 1 while, 2 for: ", 1, 2) == 1 ? 'w' : 'f';
}

void parametros(Configuracion& c, const vector<string>& t) {
    switch (c.id) {
        case 1: case 2: case 3: case 10: case 15:
            cout << "Los numeros, el nombre u otros datos se leeran AL EJECUTAR el .cpp.\n";
            break;
        case 4:
            c.fijos = siNo("¿Numero de la tabla fijo en el codigo?");
            if (c.fijos) c.tabla = entero("Numero fijo (-10000..10000): ", -10000, 10000);
            break;
        case 5: {
            int sugerido = divisorEnTexto(t);
            c.divisor = enteroSugerido("Divisor positivo 1..10000 (Enter acepta sugerido): ",
                                      sugerido == 0 ? 7 : sugerido, 1, 10000);
            cout << "Un divisor cero no se admite.\n";
            int a = entero("Resultado: 1 suma, 2 cantidad, 3 promedio: ", 1, 3);
            c.accion = a == 1 ? 's' : a == 2 ? 'c' : 'p';
            preguntarIntervalo(c, true);
            break;
        }
        case 6: {
            c.pares = entero("Filtro: 1 pares, 2 impares: ", 1, 2) == 1;
            int a = entero("Resultado: 1 suma, 2 cantidad, 3 promedio: ", 1, 3);
            c.accion = a == 1 ? 's' : a == 2 ? 'c' : 'p';
            preguntarIntervalo(c, true);
            break;
        }
        case 7:
            cout << "Se leera una cantidad positiva y luego esa cantidad de enteros.\n";
            break;
        case 8:
            c.aprobadas = siNo("¿Promedio SOLO de notas aprobadas?");
            if (c.aprobadas) c.umbral = entero("Nota minima aprobatoria (0..100): ", 0, 100);
            break;
        case 9:
            preguntarIntervalo(c, false);
            break;
        case 11:
            c.espacios = siNo("¿Texto con espacios (getline)?");
            cout << "Categorias 1 mayusculas, 2 minusculas, 3 digitos, 4 puntuacion, 5 alfanumericos.\n";
            for (int i = 0; i < 5; ++i)
                c.categorias[i] = siNo(string("¿Contar categoria ") + to_string(i+1) + "?");
            if (!c.categorias[0] && !c.categorias[1] && !c.categorias[2] &&
                !c.categorias[3] && !c.categorias[4]) {
                cout << "Seleccione al menos una categoria; se activan las cinco para revisar.\n";
                for (bool& valor : c.categorias) valor = true;
            }
            break;
        case 12: {
            c.espacios = siNo("¿Texto con espacios (getline)?");
            int a = entero("Vocales: 1 todas, 2 una concreta: ", 1, 2);
            if (a == 2) {
                while (true) {
                    string s = normalizar(leer("¿Cual vocal (a/e/i/o/u)? "));
                    if (s.size() == 1 && string("aeiou").find(s[0]) != string::npos) {
                        c.vocal = s[0]; break;
                    }
                    cout << "Elija una vocal simple.\n";
                }
            }
            break;
        }
        case 13:
            c.espacios = siNo("¿Texto con espacios (getline)?");
            c.distinguir = siNo("¿Distinguir mayusculas de minusculas?");
            c.charFijo = siNo("¿Caracter a buscar fijo en el codigo?");
            if (c.charFijo) {
                while (true) {
                    string s = leer("Caracter ASCII fijo (un byte, puede ser espacio): ");
                    if (s.size() == 1 && static_cast<unsigned char>(s[0]) < 128 &&
                        s[0] >= ' ' && s[0] != '\\' && s[0] != '\'') {
                        c.buscado = s[0]; break;
                    }
                    cout << "Escriba un unico caracter ASCII imprimible (sin barra o comilla).\n";
                }
            } else cout << "El caracter se leera por teclado AL EJECUTAR (no puede ser espacio).\n";
            break;
        case 14:
            while (true) {
                c.textoDemo = leer("Texto inicial ASCII para la demostracion (1..40 caracteres): ");
                bool valido = !c.textoDemo.empty() && c.textoDemo.size() <= 40;
                for (unsigned char b : c.textoDemo) if (b < 32 || b > 126) valido = false;
                if (valido) break;
                cout << "Solo ASCII imprimible, entre 1 y 40 caracteres.\n";
            }
            break;
    }
}

string resumen(const Configuracion& c) {
    ostringstream o;
    o << "Plantilla " << c.id << ": " << NOMBRES[c.id] << "\n";
    if (c.id == 5 || c.id == 6 || c.id == 9) {
        if (c.id == 5) o << "Divisor: " << c.divisor << "; ";
        if (c.id == 6) o << "Filtro: " << (c.pares ? "pares" : "impares") << "; ";
        if (c.id != 9) o << "Operacion: " << accionNombre(c.accion) << "; ";
        o << "Extremos: " << (c.fijos ? to_string(c.inicio) + " y " + to_string(c.final) : "leidos al ejecutar")
          << "; incluir inicio/final: " << (c.incluirInicio ? "si" : "no") << "/"
          << (c.incluirFinal ? "si" : "no") << "; exigir inicio < final: "
          << (c.validar ? "si" : "no") << "; ciclo: "
          << (c.id == 9 ? "for" : c.ciclo == 'w' ? "while" : "for") << '\n';
    }
    if (c.id == 4) o << "Numero: " << (c.fijos ? to_string(c.tabla) : "leido al ejecutar") << '\n';
    if (c.id == 8) o << "Filtro de aprobadas: " << (c.aprobadas ? "si; umbral " + to_string(c.umbral) : "no") << '\n';
    if (c.id >= 11 && c.id <= 13) o << "Texto con espacios: " << (c.espacios ? "si" : "no") << '\n';
    if (c.id == 11) {
        o << "Categorias: ";
        for (int i = 0; i < 5; ++i) if (c.categorias[i]) o << i+1 << ' ';
        o << "(alfanumericos incluyen letras y digitos, aunque coincidan)\n";
    }
    if (c.id == 12) o << "Vocales: " << (c.vocal == 't' ? "todas" : string(1, c.vocal)) << "; sin distinguir mayusculas\n";
    if (c.id == 13) o << "Caracter: " << (c.charFijo ? string("fijo '") + c.buscado + "'" : "leido al ejecutar")
                     << "; distinguir mayusculas: " << (c.distinguir ? "si" : "no") << '\n';
    if (c.id == 14) o << "Texto de demostracion: " << c.textoDemo << '\n';
    if (c.id == 15) o << "Nombre completo (con espacios), edad y sexo F/M se leeran al ejecutar.\n";
    o << "Los demas datos indicados en el .cpp se pediran cuando ejecutes ese programa.\n";
    return o.str();
}

string literalCpp(const string& texto) {
    string r = "\"";
    for (char c : texto) {
        if (c == '\\' || c == '"') r += '\\';
        r += c;
    }
    return r + "\"";
}

string comienzo(const string& enunciado, const string& algoritmo,
                const string& ejemplo, bool cadena = false, bool ctype = false) {
    // Estos textos proceden solo de frases controladas por el programa; el
    // enunciado libre del usuario JAMAS se inserta en fuente ni comentarios.
    string s = "/*\nEnunciado: " + enunciado + "\nAlgoritmo: " + algoritmo +
               "\nEjemplo: " + ejemplo +
               "\nLimites: suponer entradas del tipo solicitado, cantidades que caben en int\n"
               "y operaciones representables.\n";
    if (cadena) s += "El texto UTF-8 se recorre por bytes; vocales acentuadas, enie y\n"
                     "otros caracteres Unicode necesitan otro tratamiento.\n";
    s += "*/\n#include <iostream>\n";
    if (cadena) s += "#include <string>\n";
    if (ctype) s += "#include <cctype>\n";
    return s + "using namespace std;\n\nint main() {\n";
}

string fin() { return "    return 0;\n}\n"; }

// Se implementan las 15 salidas sin funciones propias dentro del programa alumno.
string generar(const Configuracion& c);

string guardar(const Configuracion& c, const string& contenido) {
    // El modo exclusivo crea el archivo SOLO si todavía no existe; así una
    // segunda ejecución tampoco puede sobrescribir la primera solución.
#ifdef _WIN32
    if (_mkdir("generados") != 0 && errno != EEXIST)
#else
    if (mkdir("generados", 0755) != 0 && errno != EEXIST)
#endif
        throw runtime_error("No se pudo crear la carpeta generados.");
    struct stat datos;
    if (stat("generados", &datos) != 0)
        throw runtime_error("No se pudo consultar la carpeta generados.");
#ifdef _WIN32
    if ((datos.st_mode & _S_IFDIR) == 0)
#else
    if (!S_ISDIR(datos.st_mode))
#endif
        throw runtime_error("generados no es una carpeta.");

    for (int n = 1; n <= 9999; ++n) {
        ostringstream nombre;
        nombre << "plantilla_";
        if (c.id < 10) nombre << '0';
        nombre << c.id << '_' << ARCHIVOS[c.id] << '_';
        nombre.width(4); nombre.fill('0'); nombre << n << ".cpp";
        string ruta = "generados/" + nombre.str();
#ifdef _WIN32
        int archivo = _open(ruta.c_str(), _O_WRONLY | _O_CREAT | _O_EXCL | _O_BINARY,
                            _S_IREAD | _S_IWRITE);
#else
        int archivo = open(ruta.c_str(), O_WRONLY | O_CREAT | O_EXCL, 0644);
#endif
        if (archivo == -1) {
            if (errno == EEXIST) continue;
            throw runtime_error("No se pudo crear el archivo de salida.");
        }

        size_t posicion = 0;
        while (posicion < contenido.size()) {
            // Pedazos pequeños caben también en el argumento int de _write.
            size_t longitud = min(static_cast<size_t>(32768), contenido.size() - posicion);
#ifdef _WIN32
            int escritos = _write(archivo, contenido.data() + posicion,
                                  static_cast<unsigned int>(longitud));
#else
            int escritos = static_cast<int>(write(archivo, contenido.data() + posicion, longitud));
#endif
            if (escritos <= 0) {
#ifdef _WIN32
                _close(archivo);
#else
                close(archivo);
#endif
                std::remove(ruta.c_str());
                throw runtime_error("No se pudo escribir el archivo completo.");
            }
            posicion += static_cast<size_t>(escritos);
        }
#ifdef _WIN32
        int cerrado = _close(archivo);
#else
        int cerrado = close(archivo);
#endif
        if (cerrado != 0) {
            std::remove(ruta.c_str());
            throw runtime_error("No se pudo cerrar el archivo de salida.");
        }
        return ruta;
    }
    throw runtime_error("Se agotaron los nombres consecutivos disponibles.");
}

int main() {
    try {
        cout << "ASISTENTE DE PLANTILLAS C++ (sin internet, no es IA)\n"
             << "Ejecuta este asistente DESDE la carpeta asistente_offline.\n";
        while (true) {
            int modo = entero("\n1 Escribir enunciado, 2 Elegir plantilla, 0 Salir: ", 0, 2);
            if (modo == 0) return 0;
            vector<string> t;
            Configuracion c;
            if (modo == 1) {
                t = palabras(leer("Enunciado breve: "));
                c.id = escoger(proponer(t));
            } else {
                menu();
                c.id = entero("Plantilla 1-15 (0 cancela): ", 0, 15);
            }
            if (c.id == 0) continue;
            string alertas = restricciones(t, c.id);
            if (!alertas.empty()) {
                cout << "Restricciones NO representadas:\n" << alertas;
                if (!siNo("¿Aceptas ajustar el enunciado a la plantilla SIN esas restricciones?")) continue;
            }
            cout << "Propuesta: " << NOMBRES[c.id] << '\n';
            if (!siNo("¿Confirmas usar esta plantilla?")) continue;
            parametros(c, t);
            string diferencias = conflictos(t, c);
            if (!diferencias.empty()) {
                cout << "Decisiones distintas del enunciado:\n" << diferencias;
                if (!siNo("¿Aceptas esas diferencias expresamente?")) continue;
            }
            cout << "\nRESUMEN PARA REVISAR:\n" << resumen(c);
            if (!siNo("¿Coincide con lo que necesitas y deseas guardar el .cpp?")) continue;
            string ruta = guardar(c, generar(c));
            cout << "Archivo creado: " << ruta << '\n'
                 << "Algoritmo y ejemplo: lee el comentario al comienzo del .cpp.\n"
                 << "Para compilar DESDE asistente_offline (macOS):\n"
                 << "clang++ -std=c++11 -Wall -Wextra " << ruta
                 << " -o programa_generado\n"
                 << "Luego: ./programa_generado (no se ejecuta automaticamente).\n";
        }
    } catch (const exception& error) {
        cerr << "Fin del asistente: " << error.what() << '\n';
        return 1;
    }
}

string inicioIntervalo(const Configuracion& c) {
    ostringstream o;
    o << "    int inicio; // Primer extremo del intervalo.\n"
      << "    int final;  // Ultimo extremo del intervalo.\n";
    if (c.fijos) {
        o << "    inicio = " << c.inicio << "; // Extremo fijo elegido al generar.\n"
          << "    final = " << c.final << ";\n";
    } else {
        o << "    cout << \"Inicio y final: \";\n    cin >> inicio >> final;\n";
    }
    if (c.validar) {
        if (c.fijos) {
            // Ya se comprobaron los límites fijos en el generador.
            o << "    // Al ser fijos se verifico al generar que inicio < final.\n";
        } else {
            o << "    // Se repite mientras inicio >= final: la igualdad tambien es invalida.\n"
              << "    while (inicio >= final) {\n"
              << "        cout << \"Intervalo invalido. Inicio y final otra vez: \";\n"
              << "        cin >> inicio >> final;\n"
              << "    }\n";
        }
    } else {
        o << "    // No se exige inicio < final; un rango invertido no tiene elementos.\n";
    }
    return o.str();
}

string condicionBordes(const Configuracion& c) {
    if (c.incluirInicio && c.incluirFinal) return "true";
    if (!c.incluirInicio && !c.incluirFinal)
        return "actual != inicio && actual != final";
    return c.incluirInicio ? "actual != final" : "actual != inicio";
}

string ejemploFiltrado(const Configuracion& c) {
    int desde = c.fijos ? c.inicio : 1;
    int hasta = c.fijos ? c.final : 20;
    int cantidad = 0;
    int suma = 0;
    for (int i = desde; i <= hasta; ++i) {
        if ((!c.incluirInicio && i == desde) || (!c.incluirFinal && i == hasta)) continue;
        if (c.id == 5 ? i % c.divisor == 0 :
            (c.pares ? i % 2 == 0 : i % 2 != 0)) {
            ++cantidad;
            suma += i;
        }
    }
    ostringstream o;
    o << "inicio " << desde << ", final " << hasta << " -> ";
    if (c.accion == 'c') o << "Cantidad: " << cantidad;
    else if (c.accion == 's') o << "Suma: " << suma;
    else if (cantidad == 0) o << "No hay elementos; no existe promedio";
    else o << "Promedio: " << static_cast<double>(suma) / cantidad;
    return o.str();
}

string generarFiltro(const Configuracion& c) {
    string nombreFiltro = c.id == 5 ? "multiplos de " + to_string(c.divisor) :
                                         (c.pares ? "pares" : "impares");
    string s = comienzo("Calcular " + accionNombre(c.accion) + " de " + nombreFiltro +
                         " en un intervalo.",
        "leer/definir extremos; recorrer con " + string(c.ciclo == 'w' ? "while" : "for") +
        "; filtrar, contar y sumar; si se promedia, comprobar cantidad antes de dividir.",
        ejemploFiltrado(c));
    s += inicioIntervalo(c);
    if (c.id == 5) s += "    int divisor = " + to_string(c.divisor) + "; // Divisor no nulo elegido al generar.\n";
    if (c.accion != 'c') s += "    int suma = 0; // Acumulador: inicia en cero.\n";
    if (c.accion != 's') s += "    int cantidad = 0; // Contador: inicia en cero.\n";
    s += "    // Se prueba cada entero; las comparaciones de bordes deciden inclusion.\n";
    if (c.ciclo == 'w') {
        s += "    int actual = inicio; // Valor en examen; avanzara uno a uno.\n"
             "    while (actual <= final) {\n";
    } else {
        s += "    // for: inicio; condicion; avance manual tras procesar el final.\n"
             "    for (int actual = inicio; actual <= final;) {\n";
    }
    string filtro = c.id == 5 ? "actual % divisor == 0" :
                                      (c.pares ? "actual % 2 == 0" : "actual % 2 != 0");
    s += "        // % devuelve el residuo; == comprueba igualdad, = asigna.\n";
    if (condicionBordes(c) == "true") s += "        if (" + filtro + ") {\n";
    else s += "        if ((" + condicionBordes(c) + ") && " + filtro + ") {\n";
    if (c.accion != 'c') s += "            suma += actual; // Suma el valor seleccionado.\n";
    if (c.accion != 's') s += "            cantidad++; // Suma una coincidencia al contador.\n";
    s += "        }\n"
         "        // Sin este corte, incrementar final cuando vale INT_MAX desbordaria.\n"
         "        if (actual == final) { break; }\n"
         "        actual++; // Garantiza progreso hacia el final.\n"
         "    }\n";
    if (c.accion == 'c') s += "    cout << \"Cantidad: \" << cantidad << endl;\n";
    if (c.accion == 's') s += "    cout << \"Suma: \" << suma << endl;\n";
    if (c.accion == 'p') {
        s += "    if (cantidad == 0) {\n"
             "        cout << \"No hay elementos; no existe promedio.\" << endl;\n"
             "    } else {\n"
             "        // Convertir ANTES de dividir conserva la parte decimal.\n"
             "        double promedio = static_cast<double>(suma) / cantidad;\n"
             "        cout << \"Promedio: \" << promedio << endl;\n"
             "    }\n";
    }
    return s + fin();
}

string generarPrimos(const Configuracion& c) {
    int desde = c.fijos ? c.inicio : 2;
    int hasta = c.fijos ? c.final : 10;
    ostringstream ejemplo;
    ejemplo << "inicio " << desde << ", final " << hasta << " -> Primos:";
    for (int n = desde; n <= hasta; ++n) {
        if ((!c.incluirInicio && n == desde) || (!c.incluirFinal && n == hasta)) continue;
        if (n < 2) continue;
        bool primo = true;
        for (int d = 2; d <= n / 2; ++d) if (n % d == 0) primo = false;
        if (primo) {
            ejemplo << ' ' << n;
        }
    }
    string s = comienzo("Mostrar numeros primos en el intervalo elegido.",
        "leer/definir extremos; probar cada candidato >= 2; contar divisores\n"
        "entre 2 y numero/2; si no hay ninguno, mostrar el candidato.", ejemplo.str());
    s += inicioIntervalo(c);
    s += "    cout << \"Primos: \";\n"
         "    for (int actual = inicio; actual <= final;) {\n";
    if (condicionBordes(c) == "true") s += "        if (actual >= 2) {\n";
    else s += "        if ((" + condicionBordes(c) + ") && actual >= 2) {\n";
    s +=
         "            int divisores = 0; // Se reinicia por cada candidato.\n"
         "            // Basta buscar entre 2 y actual/2: no hay otros divisores propios.\n"
         "            for (int posible = 2; posible <= actual / 2; posible++) {\n"
         "                if (actual % posible == 0) { divisores++; }\n"
         "            }\n"
         "            if (divisores == 0) { cout << actual << \" \"; }\n"
         "        }\n"
         "        if (actual == final) { break; } // Evita desbordar al avanzar.\n"
         "        actual++;\n"
         "    }\n"
         "    cout << endl;\n";
    return s + fin();
}

string lecturaTexto(const Configuracion& c) {
    return c.espacios ?
        "    cout << \"Texto (puede incluir espacios): \";\n    getline(cin, texto);\n" :
        "    cout << \"Una palabra sin espacios: \";\n    cin >> texto;\n";
}

string longitudTexto() {
    return "    // Textos habituales: size() devuelve bytes y cabe en int.\n"
           "    int longitud = static_cast<int>(texto.size());\n"
           "    for (int i = 0; i < longitud; i++) { // Indices: 0..longitud-1.\n";
}

string generar(const Configuracion& c) {
    string s;
    switch (c.id) {
        case 1:
            s = comienzo("Leer dos enteros y hacer operaciones basicas.",
                "leer ambos; calcular suma, resta y producto; si el segundo no\n"
                "es cero, calcular cocientes y residuo.",
                "entrada 10 3 -> suma 13, division entera 3, residuo 1");
            s += R"CPP(    int primero, segundo; // Operandos leidos por teclado.
    cout << "Dos enteros: "; cin >> primero >> segundo;
    cout << "Suma: " << primero + segundo << endl;
    cout << "Resta: " << primero - segundo << endl;
    cout << "Producto: " << primero * segundo << endl;
    // == compara; = asigna. Evitamos / y % cuando el divisor es cero.
    if (segundo == 0) {
        cout << "No se puede dividir entre cero." << endl;
    } else {
        cout << "Division entera: " << primero / segundo << endl;
        cout << "Division decimal: " << static_cast<double>(primero) / segundo << endl;
        cout << "Residuo: " << primero % segundo << endl;
    }
)CPP";
            break;
        case 2:
            s = comienzo("Comparar dos numeros enteros.",
                "leer ambos y elegir una sola rama: mayor, menor o igual.",
                "entrada 4 9 -> Primero menor");
            s += R"CPP(    int primero, segundo; // Valores que vamos a comparar.
    cout << "Dos enteros: "; cin >> primero >> segundo;
    if (primero > segundo) { cout << "Primero mayor" << endl; }
    else if (primero < segundo) { cout << "Primero menor" << endl; }
    else { cout << "Iguales" << endl; } // No es mayor ni menor.
    // == seria comparar igualdad; = cambiaria un valor.
)CPP";
            break;
        case 3:
            s = comienzo("Solicitar un intervalo con inicio estrictamente menor al final.",
                "leer extremos; mientras inicio >= final, volver a leer ambos.",
                "entrada 8 8, luego 2 5 -> Intervalo valido: 2 5");
            s += R"CPP(    int inicio, final; // Dos extremos leidos por teclado.
    cout << "Inicio y final: "; cin >> inicio >> final;
    while (inicio >= final) { // Igualdad e inversion son invalidas.
        cout << "Intervalo invalido. Escriba ambos otra vez: ";
        cin >> inicio >> final; // El ciclo termina cuando inicio < final.
    }
    cout << "Intervalo valido: " << inicio << " " << final << endl;
)CPP";
            break;
        case 4:
            s = comienzo("Mostrar la tabla de multiplicar del 1 al 10.",
                "obtener el numero y recorrer factores desde 1 hasta 10 con for.",
                c.fijos ? "numero fijo " + to_string(c.tabla) + " -> primera fila " +
                          to_string(c.tabla) + " x 1 = " + to_string(c.tabla) :
                          "entrada 3 -> primera fila 3 x 1 = 3");
            if (c.fijos) s += "    int numero = " + to_string(c.tabla) + "; // Numero fijo.\n";
            else s += "    int numero; // Numero elegido al ejecutar.\n"
                      "    cout << \"Numero: \"; cin >> numero;\n";
            s += R"CPP(    // Inicio 1; <= incluye 10; ++ aumenta el factor en uno.
    for (int factor = 1; factor <= 10; factor++) {
        cout << numero << " x " << factor << " = " << numero * factor << endl;
    }
)CPP";
            break;
        case 5: case 6: return generarFiltro(c);
        case 7:
            s = comienzo("Leer N enteros y contar positivos, negativos y ceros.",
                "validar N positivo; leer N valores; sumar sus valores y contar\n"
                "cada signo con condiciones excluyentes.",
                "entrada 4 y luego 2 -3 0 5 -> positivos 2, negativos 1, ceros 1, suma 4");
            s += R"CPP(    int cantidad; // Numero de lecturas que se realizaran.
    int positivos = 0, negativos = 0, ceros = 0; // Contadores en cero.
    int suma = 0; // Acumulador en cero: elemento neutro de la suma.
    cout << "Cantidad positiva: "; cin >> cantidad;
    while (cantidad <= 0) {
        cout << "Debe ser positiva. Otra cantidad: "; cin >> cantidad;
    }
    for (int i = 0; i < cantidad; i++) { // N lecturas, desde 0 hasta N-1.
        int numero; // Valor actual; se lee antes de usarlo.
        cout << "Numero: "; cin >> numero;
        suma += numero; // Acumula el valor, no solamente uno.
        if (numero > 0) { positivos++; }
        else if (numero < 0) { negativos++; }
        else { ceros++; } // Cada dato pertenece a una sola categoria.
    }
    cout << "Positivos: " << positivos << ", negativos: " << negativos
         << ", ceros: " << ceros << ", suma: " << suma << endl;
)CPP";
            break;
        case 8:
            s = comienzo(c.aprobadas ? "Promediar solo notas aprobadas." : "Promediar todas las notas.",
                "leer cantidad positiva; leer notas, filtrar si procede;\n"
                "sumar y contar; dividir solo si la cantidad seleccionada es positiva.",
                c.aprobadas ? "umbral " + to_string(c.umbral) +
                    ", entrada 2 notas: " + to_string(c.umbral) + " " +
                    to_string(c.umbral) + " -> promedio " + to_string(c.umbral) :
                    "entrada 3 notas: 60 80 100 -> promedio 80");
            s += R"CPP(    int cantidad; // Numero de notas que se leeran.
    int suma = 0, seleccionadas = 0; // Acumulador y contador empiezan en 0.
    cout << "Cantidad positiva de notas: "; cin >> cantidad;
    while (cantidad <= 0) {
        cout << "Debe ser positiva. Otra cantidad: "; cin >> cantidad;
    }
    for (int i = 0; i < cantidad; i++) {
        int nota; // Nota de esta iteracion (se supone entre 0 y 100).
        cout << "Nota: "; cin >> nota;
)CPP";
            if (c.aprobadas) {
                s += "        if (nota >= " + to_string(c.umbral) + ") { // Solo las aprobadas.\n"
                     "            suma += nota; seleccionadas++;\n"
                     "        }\n";
            } else s += "        suma += nota; seleccionadas++; // Se incluyen todas.\n";
            s += R"CPP(    }
    if (seleccionadas == 0) {
        cout << "No hay notas seleccionadas; no existe promedio." << endl;
    } else {
        // Convertir antes de / evita perder decimales por division entera.
        double promedio = static_cast<double>(suma) / seleccionadas;
        cout << "Promedio: " << promedio << endl;
    }
)CPP";
            break;
        case 9: return generarPrimos(c);
        case 10:
            s = comienzo("Calcular potencia con multiplicaciones, sin pow.",
                "iniciar en 1; multiplicar base para exponente positivo o\n"
                "1/base para negativo; cero negativo no se puede calcular.",
                "entrada base 2, exponente -3 -> Resultado: 0.125");
            s += R"CPP(    double base; // Factor que se multiplica varias veces.
    int exponente; // Signo negativo indica multiplicar su inversa.
    double potencia = 1.0; // El producto vacio (exponente 0) vale 1.
    cout << "Base y exponente entero: "; cin >> base >> exponente;
    if (base == 0.0 && exponente < 0) {
        cout << "No se puede dividir entre cero." << endl;
        return 0;
    }
    int pendientes = exponente;
    if (exponente >= 0) {
        while (pendientes > 0) {
            potencia *= base; // Equivale a potencia = potencia * base.
            pendientes--; // Queda una multiplicacion menos.
        }
    } else {
        double inversa = 1.0 / base; // Base no nula, comprobada arriba.
        while (pendientes < 0) {
            potencia *= inversa;
            pendientes++; // Evita negar el minimo int.
        }
    }
    cout << "Resultado: " << potencia << endl;
)CPP";
            break;
        case 11: {
            s = comienzo("Contar categorias seleccionadas en un texto.",
                "leer texto; recorrer bytes con at(i); usar condiciones\n"
                "independientes por categoria, pues se pueden superponer.",
                "entrada Hola 2! -> mayusculas 1, minusculas 3, digitos 1,\n"
                "puntuacion 1, alfanumericos 5 (si se seleccionan todas).", true, true);
            s += "    string texto; // Texto que se recorrera posicion por posicion.\n" + lecturaTexto(c);
            const char* nombres[5] = {"mayusculas", "minusculas", "digitos", "puntuacion", "alfanumericos"};
            const char* funcs[5] = {"isupper", "islower", "isdigit", "ispunct", "isalnum"};
            for (int i = 0; i < 5; ++i) if (c.categorias[i])
                s += string("    int ") + nombres[i] + " = 0; // Contador inicial.\n";
            s += longitudTexto();
            s += "        // cctype acepta EOF o un byte convertible a unsigned char.\n"
                 "        // Convertir ANTES impide pasar un char negativo.\n"
                 "        int caracter = static_cast<unsigned char>(texto.at(i));\n";
            for (int i = 0; i < 5; ++i) if (c.categorias[i])
                s += string("        if (") + funcs[i] + "(caracter)) { " + nombres[i] + "++; }\n";
            s += "        // if independientes: 'A' es mayuscula Y alfanumerica.\n"
                 "    }\n";
            const char* etiquetas[5] = {"Mayusculas", "Minusculas", "Digitos", "Puntuacion", "Alfanumericos"};
            for (int i = 0; i < 5; ++i) if (c.categorias[i])
                s += string("    cout << \"") + etiquetas[i] + ": \" << " + nombres[i] + " << endl;\n";
            break;
        }
        case 12:
            s = comienzo(c.vocal == 't' ? "Contar cada vocal a/e/i/o/u sin distinguir mayusculas." :
                         string("Contar la vocal ") + c.vocal + " sin distinguir mayusculas.",
                "recorrer texto con at(i); normalizar cada byte con tolower;\n"
                "contar las vocales elegidas.",
                "entrada Aula -> a 2, e 0, i 0, o 0, u 1 (si se eligen todas).", true, true);
            s += "    string texto; // Incluye espacios si se eligio getline.\n" + lecturaTexto(c);
            if (c.vocal == 't') s += "    int aes = 0, ees = 0, ies = 0, oes = 0, ues = 0; // Contadores.\n";
            else s += "    int cantidad = 0; // Comienza sin coincidencias.\n";
            s += longitudTexto();
            s += "        // Convertir a unsigned char ANTES de cctype evita bytes negativos.\n"
                 "        int letra = tolower(static_cast<unsigned char>(texto.at(i)));\n";
            if (c.vocal == 't') {
                s += R"CPP(        if (letra == 'a') { aes++; }
        else if (letra == 'e') { ees++; }
        else if (letra == 'i') { ies++; }
        else if (letra == 'o') { oes++; }
        else if (letra == 'u') { ues++; }
    }
    cout << "a: " << aes << ", e: " << ees << ", i: " << ies
         << ", o: " << oes << ", u: " << ues << endl;
)CPP";
            } else {
                s += string("        if (letra == '") + c.vocal + "') { cantidad++; }\n"
                     "    }\n";
                s += string("    cout << \"Vocal ") + c.vocal + ": \" << cantidad << endl;\n";
            }
            break;
        case 13: {
            int coincidenciasEjemplo = 0;
            for (char letra : string("banana")) {
                if (c.distinguir ? letra == c.buscado :
                    tolower(static_cast<unsigned char>(letra)) ==
                    tolower(static_cast<unsigned char>(c.buscado))) ++coincidenciasEjemplo;
            }
            string ej = c.charFijo ? string("entrada banana, caracter fijo elegido -> Apariciones: ") +
                      to_string(coincidenciasEjemplo) :
                      "entrada banana y caracter a -> Apariciones: 3";
            s = comienzo("Contar apariciones de un caracter en una cadena.",
                "leer texto y caracter; recorrer posiciones; comparar cada\n"
                "caracter segun la opcion de mayusculas.", ej, true, !c.distinguir);
            s += "    string texto; // Texto completo que se examina.\n" + lecturaTexto(c);
            if (c.charFijo) {
                s += string("    char buscado = '") + c.buscado + "'; // Elegido al generar.\n";
            } else {
                s += "    char buscado; // Se lee al ejecutar; cin >> omite blancos.\n"
                     "    cout << \"Caracter a buscar (sin espacios): \"; cin >> buscado;\n";
            }
            s += "    int apariciones = 0; // Empieza sin coincidencias.\n";
            if (!c.distinguir)
                s += "    int objetivo = tolower(static_cast<unsigned char>(buscado));\n"
                     "    // Conversion segura antes de llamar a tolower.\n";
            s += longitudTexto();
            if (c.distinguir)
                s += "        if (texto.at(i) == buscado) { apariciones++; } // == compara.\n";
            else
                s += "        int letra = tolower(static_cast<unsigned char>(texto.at(i)));\n"
                     "        if (letra == objetivo) { apariciones++; } // Ignora mayusculas ASCII.\n";
            s += "    }\n    cout << \"Apariciones: \" << apariciones << endl;\n";
            break;
        }
        case 14:
            s = comienzo("Demostrar insert, erase, push_back, substr, empty y comparar.",
                "partir de un string; insertar, borrar, anexar un caracter;\n"
                "mostrar cada cambio y examinar una subcadena y el orden.",
                "si el texto inicial fuera Sol -> Sol de -> Sol -> Sol!", true);
            s += "    string texto = " + literalCpp(c.textoDemo) + "; // Texto fijo validado al generar.\n";
            s += R"CPP(    cout << "Inicial: " << texto << endl;
    // size() apunta justo despues del ultimo caracter: agregamos ' de'.
    texto.insert(texto.size(), " de");
    cout << "Tras insert: " << texto << endl;
    // erase elimina los tres caracteres que acabamos de insertar.
    texto.erase(texto.size() - 3, 3);
    cout << "Tras erase: " << texto << endl;
    texto.push_back('!'); // Un char al final del estado ACTUAL.
    cout << "Tras push_back: " << texto << endl;
    // substr(0, 2) toma como maximo dos caracteres desde indice 0.
    cout << "Primeros dos: " << texto.substr(0, 2) << endl;
    if (texto.empty()) { cout << "Vacia" << endl; }
    else { cout << "No vacia" << endl; }
    if (texto < "sol") { cout << "Antes de sol (orden lexicografico)" << endl; }
    else { cout << "Igual o despues de sol (orden lexicografico)" << endl; }
)CPP";
            break;
        case 15:
            s = comienzo("Elegir vocal por edad y sexo F/M; contarla en nombre completo.",
                "leer edad, nombre con espacios y sexo; elegir i/a/e/o con if\n"
                "anidados; contar esa vocal ignorando mayusculas.",
                "entrada 20, Maria Isabel, F -> Vocal i: 2", true, true);
            s += R"CPP(    int edad; // La mayoria de edad comienza a los 18.
    string nombre; // Puede incluir espacios.
    char sexo, vocal = ' '; // La vocal se elige tras validar F/M.
    int cantidad = 0; // Contador sin coincidencias inicialmente.
    cout << "Edad: "; cin >> edad;
    cin.ignore(); // Descarta ENTER si la edad se escribio sola en su linea.
    cout << "Nombre completo: "; getline(cin, nombre);
    cout << "Sexo F/M: "; cin >> sexo;
    if (sexo == 'F' || sexo == 'f') {
        if (edad >= 18) { vocal = 'i'; }
        else { vocal = 'a'; }
    } else if (sexo == 'M' || sexo == 'm') {
        if (edad >= 18) { vocal = 'e'; }
        else { vocal = 'o'; }
    } else {
        cout << "Sexo invalido." << endl;
        return 0;
    }
    // Indices 0..size()-1; en UTF-8 esto recorre bytes, no letras completas.
    int longitud = static_cast<int>(nombre.size());
    for (int i = 0; i < longitud; i++) {
        // cctype requiere byte valido: convertir ANTES de tolower.
        int letra = tolower(static_cast<unsigned char>(nombre.at(i)));
        if (letra == vocal) { cantidad++; } // == compara; = asigna.
    }
    cout << "Vocal " << vocal << ": " << cantidad << endl;
)CPP";
            break;
    }
    return s + fin();
}
