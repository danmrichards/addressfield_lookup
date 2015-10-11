INTRODUCTION
------------
This module provides a PCA Predict (formerly Postcode Anywhere) based address
field lookup service. The module relies on the API and PHP interface defined in
the Address Field Lookup module.

SUPPORTED SERVICES
------------------
This module currently supported the following Postcode Anywhere Services

POSTCODEANYWHERE INTERACTIVE FIND (V1.10)
-----------------------------------------
Documentation can be found here:

http://www.pcapredict.com/support/webservice/postcodeanywhere/interactive/find/1.1/

The following formats are supported:

* JSON (http://services.postcodeanywhere.co.uk/PostcodeAnywhere/Interactive/Find/v1.10/json.ws)
* XMLA (http://services.postcodeanywhere.co.uk/PostcodeAnywhere/Interactive/Find/v1.10/xmla.ws)

REQUIREMENTS
------------
This module requires the following modules:

  * Address Field Lookup (https://drupal.org/project/addressfield_lookup)
  * Address Field (https://drupal.org/project/addressfield)
  * Chaos tool suite (https://drupal.org/project/ctools)

INSTALLATION
------------
* Enable the Address Field Lookup and Address Field Lookup Postcode Anywhere
  modules.
  - Install as you would normally install a contributed Drupal module. See:
    https://drupal.org/documentation/install/modules-themes/modules-7
    for further information.
* Clear cache.

CONFIGURATION
-------------
Configuration is provided by the Address Field Lookup module itself. Once this
sub-module is enabled you should see a new entry for Postcode Anywhere on the
overview page - admin/config/regional/addressfield-lookup.

From here you can click the 'configure' link which will take you to a form where
you can enter the API key and login for Postcode Anywhere.

MAINTAINERS
-----------
Current maintainers:
  * Dan Richards - https://www.drupal.org/user/3157375

This project has been sponsored by:
  * LUSH Digital - https://www.drupal.org/node/2529922
    In order for us to become a company of the future and clear cosmetic leader
    we are putting the internet at the heart of our business. It's time for Lush
    to be at the forefront of digital and revolutionise the cosmetics industry.

    Lush Digital enables technology to connect people throughout our community
    and build relationships bringing customer to the heart of our business.
  * FFW - https://www.drupal.org/marketplace/FFW
    FFW is a digital agency built on technology, driven by data, and focused on
    user experience.

ACKNOWLEDGEMENTS
----------------
Huge thank you to the developers/sponsors of the 'Postcodeanywhere Addressfield'
module (https://www.drupal.org/project/postcodeanywhere_addressfield). This
module is based on the concepts outlined there and without it my life would
have been much harder!

Postcodeanywhere Addressfield developers and sponsors:

  * Yuriy Gerasimov (https://www.drupal.org/u/ygerasimov)
  * Commerce Guys (https://commerceguys.com/)
  * iKOS (http://www.i-kos.com/)
