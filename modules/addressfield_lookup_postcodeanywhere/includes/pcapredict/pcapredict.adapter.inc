<?php

/**
 * @file
 * Contains the PCAPredictAdapter class.
 */

/**
 * Adapater for the PCAPredict API.
 */
class PCAPredictAdapter extends PCAPredict {

  /**
   * List of PCA Predict API endpoints. Keyed by their name.
   *
   * @var array
   *
   * @see http://www.pcapredict.com/support/webservices
   */
  private $endpoints = array(
    'Find' => 'CapturePlus/Interactive/Find/v2.10',
    'Retrieve' => 'CapturePlus/Interactive/Retrieve/v2.10',
    'CountryData' => 'Extras/Lists/CountryData/v3.00',
  );

  /**
   * Find addresses matching the search term.
   *
   * @param string $term
   *   The search term.
   * @param string $lastId
   *   The Id from a previous Find or FindByPosition.
   *
   * @return mixed
   *   Array of addresses or FALSE;
   */
  public function find($term, $lastId) {
    // Build array of parameters to pass to the API.
    $params = array(
      'SearchTerm' => $term,
      'SearchFor' => $this->filter,
      'Country' => $this->country,
    );

    // Add the last ID param if present.
    if (!is_null($lastId)) {
      $params['LastId'] = $lastId;
    }

    // Get the raw API result.
    $api_response = $this->callApi($this->endpoints['Find'], $params);

    // Bail out if there was no response.
    if (!isset($api_response)) {
      return FALSE;
    }

    // Parse the API repsonse.
    return $this->parseApiResponse($api_response);
  }

  /**
   * Returns the full address details based on the Id.
   *
   * @param string $id
   *   The ID of the address.
   *
   * @return mixed
   *   The address details or FALSE.
   */
  public function retrieve($id) {
    // The first part of the ID is the actual address ID. The second part is the
    // 'Next' operation returned by the API.
    //
    // @see http://www.pcapredict.com/support/webservice/captureplus/interactive/find/2.1/
    $id_parts = explode(':', $id);

    // Get the raw API result.
    $api_response = $this->callApi($this->endpoints['Retrieve'], array('Id' => $id_parts[0]));

    // Bail out if there was no response.
    if (!isset($api_response)) {
      return FALSE;
    }

    // Parse the API repsonse.
    return $this->parseApiResponse($api_response);
  }

  /**
   * Returns the suppported country data.
   *
   * @return mixed
   *   The set of supported country data or FALSE.
   */
  public function getCountryData() {
    // Get the raw API result.
    $api_response = $this->callApi($this->endpoints['CountryData']);

    // Bail out if there was no response.
    if (!isset($api_response)) {
      return FALSE;
    }

    // Parse the API repsonse.
    return $this->parseApiResponse($api_response);
  }

}
