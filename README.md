    

# ShapeViewer

---

`ShapeViewer` предназначен для рисования одного примитива на полотне.




# Использование

---

Для запуска приложения необходимо заполнить файл `config.yaml`.

1. **CANVAS**

    В графе `type` нужно задать вид полотна, который будет использоваться для рисования. 
    На текущий момент реализована только отрисовка в консоли (не графический режим).

    В графах `length` и `height` задаются размеры полотна.


2. **SHAPE**

    Тип фигуры выбирается изменением значения в графе `type`. Выбрать можно `circle` и `polygon`.
    1. **CIRCLE_PARAMETERS**
        
         Для круга нужно задать координаты центра `center` и его радиус `radius`.
    2. **POLYHON_PARAMETERS**
       Для полигона нужно задать координаты вершин. Координаты задаются с помощью двух векторов `x` и `y`.


# Сборка

---

`ShapeViewer` использует CMake для сборки проекта. Установите CMake перед сборкой проекта.

1. Перейдите в директорию проекта и выполните следующие команды:
```
mkdir build
cd build
cmake ..
```

