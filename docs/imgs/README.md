# Facturación Web

El sistema de facturación Web de la violeta.

* Permitir a los clientes facturar su ticket desde la comodidad de su casa.
* Que los clientes eviten formarse para solicitar una factura.
* Agilizar el proceso en las ventas de las sucursales.

En la siguiente ilustración se muestra la página principal:
<image src="docs/imgs/PagPrincipal.png" alt="Página principal">

En la siguiente ilustración se muestra el formulario para poder buscar el ticket de la venta:
<image src="docs/imgs/PagBuscarTicket.png" alt="Buscar factura por el ticket">

Completar el formulario con los datos del Ticket
<image src="docs/imgs/PagBuscarTicket1.png" alt="Buscar factura por el ticket">

## Errores o problemas al buscar el ticket 

|     Mensaje                          |Soluciones                         | Imagen|
|-------------------------------|-----------------------------|----|
|No se encontró una venta con los datos ingresados. Verifique que los datos del ticket sean correctos.          | Verificar cada uno de los datos ticket, si todos los datos son correctos debemos intentar realizar la factura más tarde.   |<image src="docs/imgs/PagBuscarTicket4.png"> |
Este ticket ya no se puede facturar. | Esto nos indica que la fecha límite para facturar o la fecha corte ya se venció, los parámetros son: MESFACTURA y DIASFACTWEB|<image src="docs/imgs/PagBuscarTicket3.png">|
Este ticket ya no se puede facturar. Es posible que ya fue facturado. |Este ticket ya fue facturado en una sucursal. |<image src="docs/imgs/PagBuscarTicket2.png">|
No se logró conectar al servidor. Inténtalo de nuevo. | Es un problema para conectarse al servidor, debemos esperar a que se restablezca. |<image src="docs/imgs/PagBuscarTicket5.png">|
¡Superaste el número máximo de peticiones fallidas para esta referencia! |Cuando se intentó realizar más del límite de peticiones por referencia, el parametro es MAXERRPETWEB. |<image src="docs/imgs/PagBuscarTicket6.png">|
¡Superaste el número máximo de peticiones por día! |Cuando se alcanzan las peticiones establecidas en el parámetro MAXPETWEB. |<image src="docs/imgs/PagBuscarTicket7.png">|
Ocurrió un error interno| Cuando se ha desconectado la base de datos, o cuando hay un error en la petición|<image src="docs/imgs/PagBuscarTicket8.png">|

## Facturar Ticket 
Completar el formulario con el RFC y el código postal
<image src="docs/imgs/PagFacturar0.png" alt="Buscar factura por el ticket">

Ahora se solicitarán los datos fiscales de la persona física o moral que se desea facturar el ticket.
 - RFC
 - Código Postal
 - Régimen Fiscal
 - Uso del CFDI

    Persona Moral
    * Razón Social

    Persona física
    * Nombres
    * Apellido Paterno
    * Apellido Materno

## Con un nuevo cliente, persona física

<image src="docs/imgs/PagFacturar2.png">

<image src="docs/imgs/PagFacturar3.png">

Si ocurre algún problema en los pasos anteriores, se deben ingresar nuevamente los datos del ticket y del cliente al que se va a facturar.

Los clientes nuevos que se registraron tendrán todo el día la opción de editar sus datos para la facturación.
<image src="docs/imgs/PagFacturar5.png">

## Con un nuevo cliente, persona moral

<image src="docs/imgs/PagFacturar6.png">
<image src="docs/imgs/PagFacturar7.png">
<image src="docs/imgs/PagFacturar8.png">

## Errores o Problemas al facturar

|     Mensaje                          |Soluciones                         | Imagen|
|-------------------------------|-----------------------------|----|
|La estructura de tu RFC es incorrecta          | El RFC no es válido, es necesario revisar la constancia de situación fiscal del cliente.  |<image src="docs/imgs/PagFacturar1.png"> |
El RFC no existe| Debemos validar que nuestro RFC sea válido ante el sat, solicitando una constancia de situación fiscal. |<image src="docs/imgs/ErrorFacturar0.png">|
El Domicilio es incorrecto| Debemos validar que nuestro código postal coincida con el domicilio registrado en el SAT, solicitando una constancia de situació fiscal. |<image src="docs/imgs/ErrorFacturar1.png">|


## Ticket Facturado Correctamente
Cuando la factura se creó correctamente, se mostrará la siguiente vista.
* Tendremos datos principales de la factura:
    * Referencia
    * Ticket
    * Fecha de compra
    * Total de la venta
    * Razón social del cliente
    * Opciones para descargar el cfdi y enviar al correo electrónico
    * Fecha hasta la cual estará disponible esta factura para consultarla.

<image src="docs/imgs/FacturaEncontrada.png">

Al presionar el boton descargar CFDI tendremos las opciones para descargar el archivo PDF y XML.
<image src="docs/imgs/FacturaEncontrada1.png">

Al presionar el boton enviar CFDI por correo  
<image src="docs/imgs/FacturaEncontrada2.png">
Si se envia correctamente se mostrara un mensaje de confirmación, el correo puede tardar unos minutos.
<image src="docs/imgs/FacturaEncontrada3.png">

## Errores o problemas al consultar el CDFI

|     Mensaje                          |Causa                         | Imagen|
|-------------------------------|-----------------------------|----|
|Esta factura ya no está disponible         | Cuando se intenta consultar una factura que ya se psaron los dias que estaba disponible, de acuerdo con el parametro DIASCONSULTAWEB |<image src="docs/imgs/ErrorFacturaEncontrada3.png"> |
|Superaste el número máximo de descargas         | Cuando se intentó realizar más del límite de peticiones de descarga por referencia, el parametro es MAXDOWLANDWEB.   |<image src="docs/imgs/ErrorFacturaEncontrada0.png"> |
No se logró conectar al Servidor|El servidor o el sincronizador estan apagados. |<image src="docs/imgs/ErrorFacturaEncontrada1.png">|
Superaste el número máximo de envió por email para esta factura|Se envio la factura a el máximo número de correos permitidos de acuerdo con el parametro MAXSENDEMAIL. |<image src="docs/imgs/ErrorFacturaEncontrada4.png">|
Superaste el número máximo de envios al correo mail@gmail.com|Se envio la factura a el máximo número de correos permitidos a el mismo e-mail de acuerdo con el parámetro MAXSENDEMAILX1. |<image src="docs/imgs/ErrorFacturaEncontrada5.png">|

## parámetros CFDIWEB
En este módulo se encuentran definidos los parámetros que se utilizaran en facturacion web.
Los permisos para acceder a este módulo son:
<image src="docs/imgs/ParametrosVista2.png">

### Acceder a el módulo parámetros facturación Web
<image src="docs/imgs/ParametrosVista0.png">
<image src="docs/imgs/ParametrosVista1.png">


|parámetro| descripción                          |
|-----|-----------------------------------------|
DIASCONSULTAWEB| Establece la cantidad de días los cuales el cliente podrá consultar la factura una vez facturada. se quedó en 12 días para esta versión|
MESFACTURA y DIASFACTWEB | Establecen la cantidad de días los cuales el cliente podría realizar la factura a su ticket, actualmente se estableció que se pueden facturar todos los días del mes de compra, con tolerancia de 7 días del siguiente mes. |
TICKETSANIOANT| Establece si se permiten facturar tickets de un año diferente al ticket, actualmente se quedó como falso, por lo que solo se pueden facturar tickets realizados en el mismo año. |
USODEFAULTWEB| Se establece el uso del cfdi por default facturador web G03|
VERSIONCFDIWEB| VERSION DE CFDI A EMITIR EN LOS DOCUMENTOS FISCALES EN WEB  4.0|
MAXDOWLANDWEB| Establece el número máximo de descargas de la factura. se estableció en 50 entre PDF y XML|
MAXERRPETWEB | Establece el número máximo de peticiones erróneas por referencia en un día, si se intenta hacer combinaciones con una misma referencia mostrara un error. |
MAXFACTERRWEB| El número de veces que se puede intentar realizar la factura de un ticket, se estableció en 5|
MAXFACTWEB| El número máximo que alguien puede facturar por día|
MAXPETWEB| El número máximo de peticiones que alguien puede hacer por día, entre consultas con éxito y erróneas    100|
MAXSENDEMAIL|   El número máximo de envíos por correo de una factura web
MAXSENDEMAILX1| El número máximo de veces que se puede enviar la factura a un mismo correo|
DIRECCION   |DIRECCIÓN DE LA SUSCURSAL C. Lago de Pátzcuaro 151, Ventura Puente, 58020 Morelia, Mich.
ECOMMERCE   |URL DEL ECOMMERCE https://superlavioleta.com/
FACEBOOK    |URL DE FACEBOOK    HTTPS://WWW.FACEBOOK.COM/SUPERVIOLETA
INSTAGRAM   |URL DE INSTAGRAM   HTTPS://WWW.INSTAGRAM.COM/SUPER_LAVIOLETA
MAIL1   |CORREO ELECTRÓNICO DE CONTACTO mail@gmail.com
MENSAJE |   MENSAJE EN EL FACTURADOR ¡Bienvenido al nuestro servicio de facturación electrónica!
TELEFONO|   TELEFONO DE CONTACTO    443 317 8919
URLAPRIVACIDAD |GUARDA EL LINK DONDE SE ENCUETRA EL AVISO DE PRIVACIDAD DE LA VIOLETA  https://cdn.shopify.com/s/files/1/0279/9265/3924/files/avisodeprivacidad.pdf?v=1634062026&embedded=true&view=FitH
SINC_WEB_ESTADO|ACTUALIZA EL SINCRONZADOR   0

## Módulo administrador facturación Web
En este módulo se encuentran definidos los parámetros que se utilizaran en facturacion web.
Los permisos para acceder a este módulo son:
<image src="docs/imgs/AdminFact0.png">

### Acceder a el módulo administrador facturación Web
<image src="docs/imgs/AdminFact1.png">

## Módulo Notas de crédito pendientes
En este módulo se mostrará el grid con las notas de crédito que se han creado en la facturación web.
* Incluir inactivos: Al marcar este check nos mostrara todas las notas de crédito que se han generado al realizar la facturación web.
- Cunado las notas de crédito están pendientes de timbrar, se muestran de color amarillo.
- Cuando las notas de crédito no se pudieron timbrar por alguna razón, se muestran en color gris.
- Las demás notas de crédito son las que ya están timbradas correctamente.

El botón Reintentar sirve para generar el CFDI a la nota de crédito, relacionada con su factura global.
Cuando se crea la factura de un ticket, este generara una nota de crédito por devolución, pero si el ticket es del mismo día no tendrá una factura global por lo que se generará la nota de crédito sin su CFDI, este proceso se completara al final del día, cuando se genere la factura global, entonces se generarán los CFDI de las notas de créditos que estén pendientes.


<image src="docs/imgs/AdminFact2.png"> 
- Al presionar el botón ver bitácora nos mostrara la bitácora en específico de esa nota de crédito.

<image src="docs/imgs/AdminFact3.png"> 

## Módulo Facturas Web
En este módulo se mostrará el grid con las facturas creadas por medio de la web.
* Incluir inactivos: Al marcar este check nos mostrara todas facturas que se generaron al realizar la facturación web (Activas e inactivas). 
* Las facturas que tienen un error o que no se pudieron timbrar correctamente se mostraran en color gris.
* En la parte lateral se mostrará información relevante de la factura generada, así como los errores que ocurrieron y las acciones que han realizado con esa factura: Descargas de PDF, XML o envios al correo electronico. 
* El botón ver bitácora nos envia al módulo para ver más detallado lo que ocurrio al generar esa factura.
* El botón Reintentar generar PDF, genera el pdf de la factura web.
<image src="docs/imgs/AdminFact4.png"> 
<image src="docs/imgs/AdminFact5.png"> 

## Módulo Bitácora errores facturación
En este módulo se mostrará el grid con los intentos de facturación, así como los detalles que se presentaron en cada uno de esos intentos.
* Check solo errores: Al marcar este check nos mostrara solo los intentos que tuvieron algún error durante la facturación web. 
* Los intentos de facturación que tuvieron error se mostraran de color amarillo.
* El botón Reintentar generar PDF, genera el pdf de la factura web.
<image src="docs/imgs/AdminFact6.png"> 

## Módulo Bitácora notas de crédito
En este módulo se mostrará el grid con los intentos de facturación, así como los detalles que se presentaron en cada uno de esos intentos.
* Check solo errores: Al marcar este check nos mostrara solo los intentos que tuvieron algún error durante la facturación web. 
* Las notas de crédito que están pendientes de timbrar se mostraran en color amarillo.
* Las notas de crédito que no se pudieron timbrar y no se guardó correctamente se mostraran en gris.

<image src="docs/imgs/AdminFact7.png"> 

## Módulo Contacto

En este módulo se mostrarán las solicitudes que se realicen por medio del apartado de contacto desde la página web. 

<image src="docs/imgs/AdminFact8.png"> 

* Se podran filtrar por tipo e incluir las preguntas de contacto que ya fueron revisadas previamente.
* En la parte derecha se mostrará la información de esa solicitud.
* Se permite marcar como revisada o como pendiente cada una de las preguntas, con el objetivo de ir ocultando las preguntas o los casos en los que se dio una solución.

## Módulo Bitácora solicitudes
En este módulo se mostrará el grid con todas las solicitudes para facturación de los tickets.
* Check solo encontrados: Al marcar este check nos muestran solo los registros cuando el ticket si fue encontrado.

<image src="docs/imgs/AdminFact9.png"> 

## Módulo preguntas frecuentes
En este módulo se mostrará el grid con las preguntas frecuentes que se mostraran en el sitio web.
* Se permite agregar nuevas preguntas o darlas de baja.
* Para dar de alta una pregunta solo presionamos el boton nueva pregunta y escribimos los campos correspondientes.
* para editar una pregunta seleccionamos la pregunta a editar y escribimos lo nuevo que deseamos agregar, presionamos en guardar y quedara guardado correctamente.

<image src="docs/imgs/AdminFact10.png"> 


## Página preguntas frecuentes
<image src="docs/imgs/PaginaPreguntas.png"> 

## Página preguntas frecuentes
<image src="docs/imgs/PaginaPreguntas.png"> 

## Página de contacto
Nos permite ponernos en contacto el departamento de sistemas para solucionar dudas, reportar problemas, etc.
<image src="docs/imgs/PagContacto.png"> 
<image src="docs/imgs/PagContacto1.png"> 

# Proceso de facturación Web

### Proceso por parte del cliente
* Venta en sucursal y entrega de ticket
* Ingresar a la página web
* Ingresar los datos del ticket
* Ingresar los datos para facturar
* Descargar su CFDI
* Listo

### Proceso por parte del servidor
* Valida toda la información del ticket
    * Venta
    * Ticket
    * Valor
    * Fecha
* Consulta o guarda la información del cliente.
    * RFC
    * Código postal
    * razón social
    * Régimen fiscal
    * Uso de cfdi
* Genera una factura con los datos del cliente y el ticket
* Si ocurre un error al timbrar la factura, se cancela la venta realizada y se guarda en la bitácora el error o los errores que ocurrieron.
* Si la factura se timbro correctamente, debemos generar una nota de crédito:
    * Si el ticket no tiene factura global relacionada, se guardará la primera parte de la nota de crédito y posteriormente cuando se genere la factura global se generará el cfdi de esta nota de crédito.
    * Si el ticket ya tiene factura global se generará la nota de crédito como el cfdi.

 
