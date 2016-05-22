<?php

/**
 * @file
 * Contains AddressFieldLookupExample.
 */

/**
 * An example Adddress Field Lookup Service.
 */
class AddressFieldLookupExample implements AddressFieldLookupInterface {

  // A mock set of lookup results.
  protected $mockResults = array(
    'TS1 1ST' => array(
      'id' => 1234,
      'street' => 'Example Street',
      'place' => 'Example City',
    ),
  );

  // A mock set of address details.
  protected $addressDetails = array(
    1234 => array(
      'id' => '1234',
      'sub_premise' => '',
      'premise' => '10',
      'thoroughfare' => 'Example Street',
      'dependent_locality' => '',
      'locality' => 'Example City',
      'postal_code' => 'TS1 1ST',
      'administrative_area' => 'Example State',
      'organisation_name' => '',
    ),
  );

  /**
   * {@inheritdoc}
   */
  public function lookup($term) {
    // Check for a valid search term in the mock results.
    if (isset($this->mockResults[$term]) && !empty($this->mockResults[$term])) {
      return array($this->mockResults[$term]);
    }
    else {
      // No result.
      return FALSE;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getAddressDetails($address_id) {
    // Check we have some address details for the ID.
    if (isset($this->addressDetails[$address_id]) && !empty($this->addressDetails[$address_id])) {
      return $this->addressDetails[$address_id];
    }
    else {
      // No result.
      return FALSE;
    }
  }

}
